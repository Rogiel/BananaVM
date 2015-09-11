//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#include <iostream>
#include "DebugInstruction.h"
#include "../ThreadContext.h"

namespace BananaVM {
	namespace Instruction {
		void DebugInstruction::perform(ThreadContext& context) {
			std::cout << "DEBUG: " << std::endl;

			std::cout << "	pc = " << context.getProgramCounter() << std::endl;
			for(int i = 0; i<BananaVM::MAX_REGISTER_COUNT; i++) {
				std::cout << "	r" << i << " = " << context.getRegister(i) << std::endl;
			}
		}
	}
}
