//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#pragma once

#include "../Opcode.h"
#include "../Memory/MemoryStore.h"

namespace BananaVM {
	namespace Assembler {

		/**
		 * The assembler is a utility class that helps generating valid assembly code for the processor.
		 *
		 * This is most useful when debugging
		 */
		class Assembler {
		public:
			/**
			 * The assembler memory store
			 */
			Memory::MemoryStore& _memoryStore;

			/**
			 * The assembler "program counter"
			 */
			MemoryAddress _pointer;

		public:
			/**
			 * Creates a new assembler for the given memory store
			 */
			Assembler(Memory::MemoryStore& memoryStore);

		public:
			/**
			 * Adds a generic opcode without any argument
			 *
			 * @param opcode the opcode to add
			 *
			 * @return this asembler
			 */
			Assembler& add(Opcode opcode);

			/**
			 * Adds a generic opcode without any argument
			 *
			 * @param opcode the opcode to add
			 *
			 * @return this asembler
			 */
			Assembler& add(Opcode opcode, MemoryByte arg0);

			/**
			 * Adds a generic opcode without any argument
			 *
			 * @param opcode the opcode to add
			 *
			 * @return this asembler
			 */
			Assembler& add(Opcode opcode, MemoryByte args0, MemoryByte arg1);

			/**
			 * Adds a generic opcode without any argument
			 *
			 * @param opcode the opcode to add
			 *
			 * @return this asembler
			 */
			Assembler& add(Opcode opcode, MemoryByte args0, MemoryByte arg1, MemoryByte arg2);

		public:
			/**
			 * Repositions the assembler head
			 *
			 * @param address the assemblers new head
			 *
			 * @return this assembler
			 */
			Assembler& seek(MemoryAddress address);

		public:
			/**
			 * Loads a constant into a register
			 *
			 * @param registerName the register to load to
			 * @param constant the constant value to load
			 *
			 * @return this assembler
			 */
			Assembler& loadConstant(RegisterName registerName, Register constant);

			/**
			 * Loads the contents of a memory address into a register
			 *
			 * @param registerName the register to load to
			 * @param address the memory address to load data from
			 *
			 * @return this assembler
			 */
			Assembler& loadAddress(RegisterName registerName, MemoryAddress address);

			/**
			 * Loads the contents of a register into a another register
			 *
			 * @param registerName the register to load to
			 * @param souceRegisterName the register to load data from
			 *
			 * @return this assembler
			 */
			Assembler& loadRegister(RegisterName registerName, RegisterName souceRegisterName);

			/**
			 * Stores the contents of a register into a memory address
			 *
			 * @param registerName the register to store the data from
			 * @param address the memory address to store content to
			 *
			 * @return this assembler
			 */
			Assembler& store(RegisterName registerName, MemoryAddress address);

			/**
			 * Performs a sum operation by adding two numbers
			 *
			 * @param registerName0 the first register to add
			 * @param registerName0 the second register to add
			 * @param resultRegisterName the register to store the sum result to
			 *
			 * @return this assembler
			 */
			Assembler& add(RegisterName registerName0, RegisterName registerName1, RegisterName resultRegisterName);

			/**
			 * Performs a subtract operation by subtracting two numbers
			 *
			 * @param registerName0 the first register to be subtracted
			 * @param registerName0 the second register to subtract from the first
			 * @param resultRegisterName the register to store the subtraction result to
			 *
			 * @return this assembler
			 */
			Assembler& subtract(RegisterName registerName0, RegisterName registerName1, RegisterName resultRegisterName);

			/**
			 * Generates a debug instruction
			 */
			Assembler& debug();

			/**
			 * Generates a halt instruction
			 */
			Assembler& halt();

		};

	}
}



