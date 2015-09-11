//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#include "MemoryInstructions.h"

#include <iostream>
#include "../ThreadContext.h"
#include "../Exception/InvalidArgumentException.h"

namespace BananaVM {
	namespace Instruction {

		LoadInstruction::LoadInstruction(Type type, RegisterName registerName, MemoryAddress memoryAddress, Register constant,
										 RegisterName sourceRegisterName) : _type(type), _registerName(registerName),
																			_memoryAddress(memoryAddress),
																			_constant(constant),
																			_sourceRegisterName(sourceRegisterName) {

		}

		void LoadInstruction::perform(ProcessorThread& thread) {
			if(_registerName == REGISTER_ACCUMULATOR |
			   _registerName == REGISTER_CARRY) {
				throw Exception::InvalidArgumentException();
			}

			auto& aRegister = thread.getContext().getRegister(_registerName);

			switch(_type) {
				case Type::CONSTANT: {
					aRegister = _constant;
					return;
				}

				case Type::ADDRESS: {
					auto& memoryResolver = thread.getMemoryResolver();
					aRegister = memoryResolver[_memoryAddress + 1] | memoryResolver[_memoryAddress] << 8;
					return;
				}


				case Type::REGISTER: {
					aRegister = thread.getContext().getRegister(_sourceRegisterName);
					return;
				}
			}
		}

		StoreInstruction::StoreInstruction(RegisterName registerName, MemoryAddress memoryAddress) :
				_registerName(registerName), _memoryAddress(memoryAddress) {}

		void StoreInstruction::perform(ProcessorThread& thread) {
			auto& memoryResolver = thread.getMemoryResolver();
			auto& aRegister = thread.getContext().getRegister(_registerName);

			memoryResolver[_memoryAddress] = (aRegister & 0xFF00) >> 8;
			memoryResolver[_memoryAddress+1] = (aRegister & 0x00FF);
		}

	}
}
