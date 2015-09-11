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
		 * Implements the STORE instruction
		 */
		class StoreInstruction : public Instruction {
		private:
			/**
			 * The source register name (i.e. the register to read the from)
			 */
			RegisterName _registerName;

			/**
			 * The destination memory address
			 */
			MemoryAddress _memoryAddress;

		public:
			/**
			 * Creates a new STORE instruction
			 *
			 * @param registerName the source register name (i.e. the register to read the from)
			 * @param memoryAddress the destination memory address
			 */
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
