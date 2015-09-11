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

