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
		 * Implements the GREATER_THAN instruction
		 */
		class GreaterThanInstruction : public BinaryInstruction {
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
		 * Implements the GREATER_OR_EQUAL_THAN instruction
		 */
		class GreaterOrEqualThanInstruction : public BinaryInstruction {
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
		 * Implements the LESS_THAN instruction
		 */
		class LessThanInstruction : public BinaryInstruction {
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
		 * Implements the LESS_OR_EQUAL_THAN instruction
		 */
		class LessOrEqualThanInstruction : public BinaryInstruction {
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
		 * Implements the EQUAL instruction
		 */
		class EqualInstruction : public BinaryInstruction {
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
		 * Implements the NOT_EQUAL instruction
		 */
		class NotEqualInstruction : public BinaryInstruction {
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
