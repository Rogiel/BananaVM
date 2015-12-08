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

			Assembler& mark(MemoryAddress& address);

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

		public:
			/**
			 * Performs a sum operation by adding two numbers
			 *
			 * @param registerName0 the first register to add
			 * @param registerName0 the second register to add
			 * @param resultRegisterName the register to store the sum result to
			 *
			 * @return this assembler
			 */
			Assembler& add(RegisterName registerName0, RegisterName registerName1);

			/**
			 * Performs a subtract operation by subtracting two numbers
			 *
			 * @param registerName0 the first register to be subtracted
			 * @param registerName0 the second register to subtract from the first
			 * @param resultRegisterName the register to store the subtraction result to
			 *
			 * @return this assembler
			 */
			Assembler& subtract(RegisterName registerName0, RegisterName registerName1);

			/**
			 * Performs a multiply operation by multiplying two numbers
			 *
			 * @param registerName0 the first register to be multiplied
			 * @param registerName0 the second register to multiplied with the first
			 * @param resultRegisterName the register to store the multiplication result to
			 *
			 * @return this assembler
			 */
			Assembler& multiply(RegisterName registerName0, RegisterName registerName1);

			/**
			 * Performs a divides operation by dividing two numbers
			 *
			 * @param registerName0 the first register to be divided
			 * @param registerName0 the second register to divided with the first
			 * @param resultRegisterName the register to store the division result to
			 *
			 * @return this assembler
			 */
			Assembler& divide(RegisterName registerName0, RegisterName registerName1);

		public:
			Assembler& bitwiseAnd(RegisterName registerName0, RegisterName registerName1);
			Assembler& bitwiseOr(RegisterName registerName0, RegisterName registerName1);
			Assembler& bitwiseNand(RegisterName registerName0, RegisterName registerName1);
			Assembler& bitwiseXor(RegisterName registerName0, RegisterName registerName1);
			Assembler& bitwiseNot(RegisterName registerName0);
			Assembler& bitwiseRightShift(RegisterName registerName0, RegisterName registerName1);
			Assembler& bitwiseLeftShift(RegisterName registerName0, RegisterName registerName1);

		public:
			Assembler& jump(MemoryAddress memoryAddress);
			Assembler& jumpIf(RegisterName registerName, MemoryAddress memoryAddress);
			Assembler& jumpIfCarry(MemoryAddress memoryAddress);

		public:
			Assembler& greaterThan(RegisterName registerName0, RegisterName registerName1);
			Assembler& greaterOrEqualThan(RegisterName registerName0, RegisterName registerName1);

			Assembler& lessThan(RegisterName registerName0, RegisterName registerName1);
			Assembler& lessOrEqualThan(RegisterName registerName0, RegisterName registerName1);

			Assembler& equal(RegisterName registerName0, RegisterName registerName1);
			Assembler& notEqual(RegisterName registerName0, RegisterName registerName1);

		public:
			/**
			 * Generates a debug instruction
			 */
			Assembler& debug();

			/**
			 * Generates a halt instruction
			 */
			Assembler& halt();

		public:
			Assembler& writeIO(RegisterName registerName);
			Assembler& readIO(RegisterName registerName);

		public:
			void printMemoryArray();

		};

	}
}



