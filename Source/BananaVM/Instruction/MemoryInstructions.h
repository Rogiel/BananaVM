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
		class LoadInstruction : public Instruction {
		public:
			enum class Type {
				REGISTER = 0b0000,
				ADDRESS = 0b0001,
				CONSTANT = 0b0010
			};

		private:
			/**
			 * The load type
			 */
			Type _type;

			/**
			 * The register to load the requested value to
			 */
			RegisterName _registerName;

			/**
			 * The memory address to load the data from
			 */
			MemoryAddress _memoryAddress;

			/**
			 * The constant value to be read
			 */
			Register _constant;

			/**
			 * The souce register name
			 */
			RegisterName _sourceRegisterName;

		public:

			/**
			 * Creates a new LOAD instruction
			 *
			 * @param type the load type
			 * @param registerName the register to load the requested value to
			 * @param memoryAddress the memory address to load the data from
			 * @param constant the constant value to be read
			 * @param sourceRegisterName the souce register name
			 */
			LoadInstruction(Type type, RegisterName registerName, MemoryAddress memoryAddress, Register constant, RegisterName sourceRegisterName);

		public:
			/**
			 * Executes the instruction
			 *
			 * @param context the processor context
			 */
			virtual void perform(ProcessorThread& thread) override;

		};

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
