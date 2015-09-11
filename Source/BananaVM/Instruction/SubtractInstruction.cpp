//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#include <iostream>
#include "SubtractInstruction.h"

#include "../ThreadContext.h"

namespace BananaVM {
	namespace Instruction {

		SubtractInstruction::SubtractInstruction(RegisterName register0, RegisterName register1, RegisterName resultRegister) :
			_register0(register0), _register1(register1), _resultRegister(resultRegister) { }

		void SubtractInstruction::perform(ProcessorThread& thread) {
			auto a = thread.getContext().getRegister(_register0);
			auto b = thread.getContext().getRegister(_register1);
			auto& result = thread.getContext().getRegister(_resultRegister);

			// TODO handle carry out
			result = a - b;
		}
	}
}
