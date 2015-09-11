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

		class UnaryInstruction : public Instruction {
		protected:
			/**
			 * The first register to be operated on
			 */
			RegisterName _register0;

		public:
			/**
			 * Creates a new unary instruction
			 *
			 * @param register0 the register to be operated on
			 */
			UnaryInstruction(RegisterName register0);

		};

		class BinaryInstruction : public Instruction {
		protected:
			/**
			 * The first register to be operated on
			 */
			RegisterName _register0;

			/**
			 * The first register to be operated on
			 */
			RegisterName _register1;

		public:
			/**
			 * Creates a new binary instruction
			 *
			 * @param register0 the first register to be operated on
			 * @param register1 the second register to be operated on
			 */
			BinaryInstruction(RegisterName register0, RegisterName register1);

		};
	}
}


