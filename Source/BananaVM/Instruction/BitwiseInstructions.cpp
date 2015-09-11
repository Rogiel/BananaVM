//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#include "BitwiseInstructions.h"

#include <iostream>
#include "../ThreadContext.h"

namespace BananaVM {
	namespace Instruction {

		void AndInstruction::perform(ProcessorThread& thread) {
			auto a = thread.getContext().getRegister(_register0);
			auto b = thread.getContext().getRegister(_register1);
			auto& result = thread.getContext().getAccumulatorRegister();

			result = a & b;
		}

		void OrInstruction::perform(ProcessorThread& thread) {
			auto a = thread.getContext().getRegister(_register0);
			auto b = thread.getContext().getRegister(_register1);
			auto& result = thread.getContext().getAccumulatorRegister();

			result = a | b;
		}

		void NandInstruction::perform(ProcessorThread& thread) {
			auto a = thread.getContext().getRegister(_register0);
			auto b = thread.getContext().getRegister(_register1);
			auto& result = thread.getContext().getAccumulatorRegister();

			result = ~(a & b);
		}

		void XorInstruction::perform(ProcessorThread& thread) {
			auto a = thread.getContext().getRegister(_register0);
			auto b = thread.getContext().getRegister(_register1);
			auto& result = thread.getContext().getAccumulatorRegister();

			result = a ^ b;
		}

		void NotInstruction::perform(ProcessorThread& thread) {
			auto a = thread.getContext().getRegister(_register0);
			auto& result = thread.getContext().getAccumulatorRegister();

			result = ~a;
		}

		void RightShiftInstruction::perform(ProcessorThread& thread) {
			auto a = thread.getContext().getRegister(_register0);
			auto b = thread.getContext().getRegister(_register1);
			auto& result = thread.getContext().getAccumulatorRegister();

			result = a >> b;
		}

		void LeftShiftInstruction::perform(ProcessorThread& thread) {
			auto a = thread.getContext().getRegister(_register0);
			auto b = thread.getContext().getRegister(_register1);
			auto& result = thread.getContext().getAccumulatorRegister();

			result = a << b;
		}
	}
}
