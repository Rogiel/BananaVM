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
		 * Implements the JUMP instruction
		 */
		class JumpInstruction : public Instruction {
		private:
			/**
			 * The memory address to jump to
			 */
			MemoryAddress _memoryAddress;

		public:
			/**
			 * Creates a new jump instruction
			 *
			 * @param memoryAddress the jumping memory address
			 */
			JumpInstruction(MemoryAddress memoryAddress);

		public:
			/**
			 * Executes the instruction
			 *
			 * @param context the processor context
			 */
			virtual void perform(ProcessorThread& thread) override;

		};

		/**
		 * Implements the CONDITIONAL_JUMP instruction
		 */
		class ConditionalJumpInstruction : public UnaryInstruction {
		private:
			/**
			 * The memory address to jump to
			 */
			MemoryAddress _memoryAddress;

		public:
			/**
			 * Creates a new jump instruction
			 *
			 * @param memoryAddress the jumping memory address
			 */
			ConditionalJumpInstruction(RegisterName registerName, MemoryAddress memoryAddress);

		public:
			/**
			 * Executes the instruction
			 *
			 * @param context the processor context
			 */
			virtual void perform(ProcessorThread& thread) override;

		};

		/**
		 * Implements the JUMP_IF_CARRY instruction
		 */
		class JumpIfCarryInstruction : public Instruction {
		private:
			/**
			 * The memory address to jump to
			 */
			MemoryAddress _memoryAddress;

		public:
			/**
			 * Creates a new jump instruction
			 *
			 * @param memoryAddress the jumping memory address
			 */
			JumpIfCarryInstruction(MemoryAddress memoryAddress);

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
