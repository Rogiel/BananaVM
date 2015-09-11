//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#include <iostream>
#include "LoadInstruction.h"

namespace BananaVM {
	namespace Instruction {
		void LoadInstruction::perform(ThreadContext& context) {
			std::cout << "LOAD" << std::endl;
		}
	}
}
