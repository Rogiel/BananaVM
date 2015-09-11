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
		 * Implements the ADD instruction
		 */
		class AddInstruction : public BinaryInstruction {
		public:
			using BinaryInstruction::BinaryInstruction;

		public:
			/**
			 * Executes the instruction
			 *
			 * @param context the processor context
			 */
			virtual void perform(ProcessorThread& thread) override;

		};

		/**
		 * Implements the SUBTRACT instruction
		 */
		class SubtractInstruction : public BinaryInstruction {
		public:
			using BinaryInstruction::BinaryInstruction;

		public:
			/**
			 * Executes the instruction
			 *
			 * @param context the processor context
			 */
			virtual void perform(ProcessorThread& thread) override;

		};

		/**
		 * Implements the MULTIPLY instruction
		 */
		class MultiplyInstruction : public BinaryInstruction {
		public:
			using BinaryInstruction::BinaryInstruction;

		public:
			/**
			 * Executes the instruction
			 *
			 * @param context the processor context
			 */
			virtual void perform(ProcessorThread& thread) override;

		};

		/**
		 * Implements the DIVIDE instruction
		 */
		class DivideInstruction : public BinaryInstruction {
		public:
			using BinaryInstruction::BinaryInstruction;

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
