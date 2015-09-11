//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#include <iostream>
#include "StoreInstruction.h"

#include "../ThreadContext.h"

namespace BananaVM {
	namespace Instruction {

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
