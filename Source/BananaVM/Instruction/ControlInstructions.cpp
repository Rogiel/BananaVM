//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#include "ControlInstructions.h"

#include <iostream>
#include "../ThreadContext.h"

namespace BananaVM {
	namespace Instruction {

		void HaltInstruction::perform(ProcessorThread& thread) {
			std::cout << "HALT" << std::endl;
			thread.getContext().setHalted(true);
		}

		void DebugInstruction::perform(ProcessorThread& thread) {
			std::cout << "DEBUG: ";

			std::cout << "pc = " << thread.getContext().getProgramCounter() << ", ";
			for(int i = 0; i<BananaVM::MAX_REGISTER_COUNT; i++) {
				std::cout << "r" << i << " = " << thread.getContext().getRegister(i) << ", ";
			}
			std::cout << std::endl;
		}

	}
}
