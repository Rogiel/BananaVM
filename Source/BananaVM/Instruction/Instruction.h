//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#pragma once

#include "../ProcessorThread.h"

namespace BananaVM {
	namespace Instruction {

		/**
		 * Abstract class that provides a interface that instruction should implement.
		 */
		class Instruction {
		public:
			/**
			 * Executes the instruction
			 *
			 * @param context the processor context
			 */
			virtual void perform(ProcessorThread& thread) = 0;

		};
	}
}


