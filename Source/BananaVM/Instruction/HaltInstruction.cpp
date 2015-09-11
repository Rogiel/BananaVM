//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#include <iostream>
#include "HaltInstruction.h"
#include "../ThreadContext.h"

namespace BananaVM {
	namespace Instruction {
		void HaltInstruction::perform(ProcessorThread& thread) {
			std::cout << "HALT" << std::endl;
			thread.getContext().setHalted(true);
		}
	}
}
