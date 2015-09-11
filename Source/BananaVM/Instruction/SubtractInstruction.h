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
		 * Implements the SUBTRACT instruction
		 */
		class SubtractInstruction : public Instruction {
		private:
			/**
			 * The first register to be subtracted
			 */
			RegisterName _register0;

			/**
			 * The second register to be subtracted
			 */
			RegisterName _register1;

			/**
			 * The register in which the result should be put
			 */
			RegisterName _resultRegister;

		public:
			/**
			 * Creates a new SUBTRACT instruction
			 *
			 * @param register0 the first register to be subtracted
			 * @param register1 the second register to be subtracted
			 * @param resultRegister the register in which the result should be put
			 */
			SubtractInstruction(RegisterName register0, RegisterName register1, RegisterName resultRegister);

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
