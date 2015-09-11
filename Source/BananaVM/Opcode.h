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
		LOAD = 0x00,

		/**
		 * Stores a registers content into a memory address
		 */
		STORE = 0x01,

		ADD = 0x10,
		SUBTRACT = 0x11,
		MULTIPLY = 0x12,
		DIVIDE = 0x13,

		JUMP = 0x20,
		CONDITIONAL_JUMP = 0x21,

		GREATER_THAN = 0x30,
		GREATER_OR_EQUAL_THAN = 0x31,
		LESS_THAN = 0x32,
		LESS_OR_EQUAL_THAN = 0x33,
		EQUAL = 0x34,
		NOT_EQUAL = 0x35,

		AND = 0x40,
		OR = 0x41,
		NAND = 0x42,
		XOR = 0x43,
		NOT = 0x44,
		RIGHT_SHIFT = 0x45,
		LEFT_SHIFT = 0x46,

		/**
		 * Halts the processor.
		 *
		 * Catching fire is optional :)
		 */
		HALT = 0xfe,

		/**
		 * A debug instruction that is only available on the VM. Prints the processor context and state to the console
		 */
		DEBUG = 0xff
	};

}

