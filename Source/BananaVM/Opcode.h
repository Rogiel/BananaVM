//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#pragma once

#include "Types.h"

namespace BananaVM {

	/**
	 * Enum representing all known (and valid) opcodes
	 */
	enum class Opcode : MemoryByte {
		/**
		 * Loads the contents of memory into a register
		 */
		LOAD = 0b00000000,

		/**
		 * Stores a registers content into a memory address
		 */
		STORE = 0b00000001,

		WRITE_IO = 0b00000010,
		READ_IO = 0b00000011,

		ADD = 0b00010000,
		SUBTRACT = 0b00010001,
		MULTIPLY = 0b00010010,
		DIVIDE = 0b00010011,

		JUMP = 0b00100000,
		CONDITIONAL_JUMP = 0x21,
		JUMP_IF_CARRY = 0b00100010,

		GREATER_THAN = 0b00110000,
		GREATER_OR_EQUAL_THAN = 0b00110001,
		LESS_THAN = 0b00110010,
		LESS_OR_EQUAL_THAN = 0b00110011,
		EQUAL = 0b00110100,
		NOT_EQUAL = 0b00110101,

		AND = 0b01000000,
		OR = 0b01000001,
		NAND = 0b01000010,
		XOR = 0b01000100,
		NOR = 0b01000011,
		NOT = 0b01000101,
		RIGHT_SHIFT = 0b01001000,
		LEFT_SHIFT = 0b01001001,

		/**
		 * Halts the processor.
		 *
		 * Catching fire is optional :)
		 */
		HALT = 0b11111110,

		/**
		 * A debug instruction that is only available on the VM. Prints the processor context and state to the console
		 */
		DEBUG = 0b11111111
	};

}

