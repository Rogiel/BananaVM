//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#include <iostream>
#include "Assembler.h"

namespace BananaVM {
	namespace Assembler {


		Assembler::Assembler(Memory::MemoryStore& memoryStore) : _memoryStore(memoryStore), _pointer(0) {}

		Assembler& Assembler::add(Opcode opcode) {
			_memoryStore[_pointer++] = static_cast<MemoryByte>(opcode);
			return *this;
		}

		Assembler& Assembler::loadConstant(RegisterName registerName, Register constant) {
			return add(
					Opcode::LOAD,
					static_cast<MemoryByte>((registerName & 0b00001111) | 0b0010 << 4),
					static_cast<MemoryByte>((constant & 0xFF00) >> 8),
					static_cast<MemoryByte>(constant & 0x00FF)
			);
		}

		Assembler& Assembler::loadAddress(RegisterName registerName, MemoryAddress address) {
			return add(
					Opcode::LOAD,
					static_cast<MemoryByte>((registerName & 0b00001111) | 0b0001 << 4),
					static_cast<MemoryByte>((address & 0xFF00) >> 8),
					static_cast<MemoryByte>(address & 0x00FF)
			);
		}

		Assembler& Assembler::loadRegister(RegisterName registerName, RegisterName address) {
			return add(
					Opcode::LOAD,
					static_cast<MemoryByte>((registerName & 0b00001111) | 0b0000 << 4),
					static_cast<MemoryByte>((address & 0b00001111) >> 8)
			);
		}

		Assembler& Assembler::debug() {
			return add(Opcode::DEBUG);
		}

		Assembler& Assembler::halt() {
			return add(Opcode::HALT);
		}

		Assembler& Assembler::add(Opcode opcode, MemoryByte arg0) {
			_memoryStore[_pointer++] = static_cast<MemoryByte>(opcode);
			_memoryStore[_pointer++] = arg0;
			return *this;
		}

		Assembler& Assembler::add(Opcode opcode, MemoryByte arg0, MemoryByte arg1) {
			_memoryStore[_pointer++] = static_cast<MemoryByte>(opcode);
			_memoryStore[_pointer++] = arg0;
			_memoryStore[_pointer++] = arg1;
			return *this;
		}

		Assembler& Assembler::add(Opcode opcode, MemoryByte arg0, MemoryByte arg1, MemoryByte arg2) {
			_memoryStore[_pointer++] = static_cast<MemoryByte>(opcode);
			_memoryStore[_pointer++] = arg0;
			_memoryStore[_pointer++] = arg1;
			_memoryStore[_pointer++] = arg2;
			return *this;
		}
	}
}