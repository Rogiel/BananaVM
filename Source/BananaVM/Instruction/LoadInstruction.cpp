//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#include <iostream>
#include "LoadInstruction.h"

#include "../ThreadContext.h"

namespace BananaVM {
	namespace Instruction {

		LoadInstruction::LoadInstruction(Type type, RegisterName registerName, MemoryAddress memoryAddress, Register constant,
										 RegisterName sourceRegisterName) : _type(type), _registerName(registerName),
																			_memoryAddress(memoryAddress),
																			_constant(constant),
																			_sourceRegisterName(sourceRegisterName) {

		}

		void LoadInstruction::perform(ProcessorThread& thread) {
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
	}
}
