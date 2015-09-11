//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#include "ComparisionInstructions.h"

#include <iostream>
#include "../ThreadContext.h"

namespace BananaVM {
	namespace Instruction {

		void GreaterThanInstruction::perform(ProcessorThread& thread) {
			auto a = thread.getContext().getRegister(_register0);
			auto b = thread.getContext().getRegister(_register1);
			auto& result = thread.getContext().getCarryRegister();

			result = static_cast<MemoryByte>(a > b ? 1 : 0);
		}

		void GreaterOrEqualThanInstruction::perform(ProcessorThread& thread) {
			auto a = thread.getContext().getRegister(_register0);
			auto b = thread.getContext().getRegister(_register1);
			auto& result = thread.getContext().getCarryRegister();

			result = static_cast<MemoryByte>(a >= b ? 1 : 0);
		}

		void LessThanInstruction::perform(ProcessorThread& thread) {
			auto a = thread.getContext().getRegister(_register0);
			auto b = thread.getContext().getRegister(_register1);
			auto& result = thread.getContext().getCarryRegister();

			result = static_cast<MemoryByte>(a < b ? 1 : 0);
		}

		void LessOrEqualThanInstruction::perform(ProcessorThread& thread) {
			auto a = thread.getContext().getRegister(_register0);
			auto b = thread.getContext().getRegister(_register1);
			auto& result = thread.getContext().getCarryRegister();

			result = static_cast<MemoryByte>(a <= b ? 1 : 0);
		}

		void EqualInstruction::perform(ProcessorThread& thread) {
			auto a = thread.getContext().getRegister(_register0);
			auto b = thread.getContext().getRegister(_register1);
			auto& result = thread.getContext().getCarryRegister();

			result = static_cast<MemoryByte>(a == b ? 1 : 0);
		}

		void NotEqualInstruction::perform(ProcessorThread& thread) {
			auto a = thread.getContext().getRegister(_register0);
			auto b = thread.getContext().getRegister(_register1);
			auto& result = thread.getContext().getCarryRegister();

			result = static_cast<MemoryByte>(a != b ? 1 : 0);
		}
	}
}
