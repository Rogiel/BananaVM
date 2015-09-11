//
//  Juice - Peer to Peer Networking library
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
			Assembler& loadAddress(RegisterName registerName, MemoryAddress address);

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



