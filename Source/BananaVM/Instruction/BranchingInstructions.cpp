//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#include "BranchingInstructions.h"

#include <iostream>
#include "../ThreadContext.h"

namespace BananaVM {
	namespace Instruction {


		JumpInstruction::JumpInstruction(MemoryAddress memoryAddress) : _memoryAddress(memoryAddress) { }

		void JumpInstruction::perform(ProcessorThread& thread) {
			auto& pc = thread.getContext().getProgramCounter();
			pc = _memoryAddress;
		}

		ConditionalJumpInstruction::ConditionalJumpInstruction(RegisterName registerName, MemoryAddress memoryAddress)
				: UnaryInstruction(registerName), _memoryAddress(memoryAddress)  {

		}

		void ConditionalJumpInstruction::perform(ProcessorThread& thread) {
			auto& conditional = thread.getContext().getRegister(_register0);
			if(conditional) {
				auto& pc = thread.getContext().getProgramCounter();
				pc = _memoryAddress;
			}
		}

		JumpIfCarryInstruction::JumpIfCarryInstruction(MemoryAddress memoryAddress) : _memoryAddress(memoryAddress) { }

		void JumpIfCarryInstruction::perform(ProcessorThread& thread) {
			auto& carry = thread.getContext().getCarryRegister();
			if(carry) {
				auto& pc = thread.getContext().getProgramCounter();
				pc = _memoryAddress;
			}
		}
	}
}
