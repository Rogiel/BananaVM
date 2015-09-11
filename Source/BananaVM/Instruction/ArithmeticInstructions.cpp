//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#include "ArithmeticInstructions.h"

#include <iostream>
#include "../ThreadContext.h"

namespace BananaVM {
	namespace Instruction {

//		AddInstruction::AddInstruction(RegisterName register0, RegisterName register1) : ArithmeticInstruction(register0, register1) { }

		void AddInstruction::perform(ProcessorThread& thread) {
			auto a = thread.getContext().getRegister(_register0);
			auto b = thread.getContext().getRegister(_register1);
			auto& result = thread.getContext().getAccumulatorRegister();
			auto& carry = thread.getContext().getCarryRegister();

			result = a + b;
			carry = (result < a) | (result < b);
		}

//		SubtractInstruction::SubtractInstruction(RegisterName register0, RegisterName register1) : ArithmeticInstruction(register0, register1){ }

		void SubtractInstruction::perform(ProcessorThread& thread) {
			auto a = thread.getContext().getRegister(_register0);
			auto b = thread.getContext().getRegister(_register1);
			auto& result = thread.getContext().getAccumulatorRegister();
//			auto& carry = thread.getContext().getCarryRegister();

			// TODO handle carry out
			result = a - b;
//			carry = (result > a) | (result > b);
		}

		void MultiplyInstruction::perform(ProcessorThread& thread) {
			auto a = thread.getContext().getRegister(_register0);
			auto b = thread.getContext().getRegister(_register1);
			auto& result = thread.getContext().getAccumulatorRegister();

			result = a * b;
		}

		void DivideInstruction::perform(ProcessorThread& thread) {
			auto a = thread.getContext().getRegister(_register0);
			auto b = thread.getContext().getRegister(_register1);
			auto& result = thread.getContext().getAccumulatorRegister();

			result = a / b;
		}
	}
}
