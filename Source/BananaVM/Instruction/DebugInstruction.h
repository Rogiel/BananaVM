//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#pragma once

#include "Instruction.h"

namespace BananaVM {
	namespace Instruction {

		/**
		 * Implements the LOAD instruction
		 */
		class DebugInstruction : public Instruction {
		public:
			/**
			 * Executes the instruction
			 *
			 * @param context the processor context
			 */
			virtual void perform(ThreadContext& context) override;

		};
	}
}


