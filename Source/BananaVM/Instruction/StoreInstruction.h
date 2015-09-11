//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#pragma once

#include "Instruction.h"
#include "../Types.h"

namespace BananaVM {
	namespace Instruction {

		/**
		 * Implements the LOAD instruction
		 */
		class StoreInstruction : public Instruction {
		private:
			RegisterName _registerName;
			MemoryAddress _memoryAddress;

		public:
			StoreInstruction(RegisterName registerName, MemoryAddress memoryAddress);

		public:
			/**
			 * Executes the instruction
			 *
			 * @param context the processor context
			 */
			virtual void perform(ProcessorThread& thread) override;

		};
	}
}
