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
		 * Implements the AND instruction
		 */
		class AndInstruction : public BinaryInstruction {
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
		 * Implements the OR instruction
		 */
		class OrInstruction : public BinaryInstruction {
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
		 * Implements the NAND instruction
		 */
		class NandInstruction : public BinaryInstruction {
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
		 * Implements the XOR instruction
		 */
		class XorInstruction : public BinaryInstruction {
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
		 * Implements the NOT instruction
		 */
		class NotInstruction : public UnaryInstruction {
		public:
			using UnaryInstruction::UnaryInstruction;

		public:
			/**
			 * Executes the instruction
			 *
			 * @param context the processor context
			 */
			virtual void perform(ProcessorThread& thread) override;

		};

		/**
		 * Implements the RIGHT_SHIFT instruction
		 */
		class RightShiftInstruction : public BinaryInstruction {
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
		 * Implements the LEFT_SHIFT instruction
		 */
		class LeftShiftInstruction : public BinaryInstruction {
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
