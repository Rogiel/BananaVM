//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#include <iostream>
#include "Assembler.h"
#include "../Instruction/LoadInstruction.h"

namespace BananaVM {
	namespace Assembler {


		Assembler::Assembler(Memory::MemoryStore& memoryStore) : _memoryStore(memoryStore), _pointer(0) {}

		Assembler& Assembler::add(Opcode opcode) {
			_memoryStore[_pointer++] = static_cast<MemoryByte>(opcode);
			return *this;
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

		Assembler& Assembler::seek(MemoryAddress address) {
			_pointer = address;
			return *this;
		}

		Assembler& Assembler::loadConstant(RegisterName registerName, Register constant) {
			return add(
					Opcode::LOAD,
					static_cast<MemoryByte>((registerName & 0b00001111) |
							(static_cast<MemoryByte>(Instruction::LoadInstruction::Type::CONSTANT) & 0b1111) << 4),
					static_cast<MemoryByte>((constant & 0xFF00) >> 8),
					static_cast<MemoryByte>(constant & 0x00FF)
			);
		}

		Assembler& Assembler::loadAddress(RegisterName registerName, MemoryAddress address) {
			return add(
					Opcode::LOAD,
					static_cast<MemoryByte>((registerName & 0b00001111) |
							(static_cast<MemoryByte>(Instruction::LoadInstruction::Type::ADDRESS) & 0b1111) << 4),
					static_cast<MemoryByte>((address & 0xFF00) >> 8),
					static_cast<MemoryByte>(address & 0x00FF)
			);
		}

		Assembler& Assembler::loadRegister(RegisterName registerName, RegisterName address) {
			return add(
					Opcode::LOAD,
					static_cast<MemoryByte>((registerName & 0b00001111) |
							(static_cast<MemoryByte>(Instruction::LoadInstruction::Type::REGISTER) & 0b1111) << 4),
					static_cast<MemoryByte>((address & 0b00001111) >> 8)
			);
		}

		Assembler& Assembler::store(RegisterName registerName, MemoryAddress address) {
			return add(
					Opcode::STORE,
					static_cast<MemoryByte>((registerName & 0b00001111) |
											(static_cast<MemoryByte>(Instruction::LoadInstruction::Type::REGISTER) & 0b1111) << 4),
					static_cast<MemoryByte>((address & 0xFF00) >> 8),
					static_cast<MemoryByte>(address & 0x00FF)
			);
		}

		Assembler& Assembler::add(RegisterName registerName0, RegisterName registerName1, RegisterName resultRegisterName) {
			return add(
					Opcode::ADD,
					static_cast<MemoryByte>(resultRegisterName & 0b00001111),
					static_cast<MemoryByte>(
							(registerName0 & 0b00001111) | ((registerName1 & 0b00001111) << 4)
					)
			);
		}

		Assembler& Assembler::subtract(RegisterName registerName0, RegisterName registerName1, RegisterName resultRegisterName) {
			return add(
					Opcode::SUBTRACT,
					static_cast<MemoryByte>(resultRegisterName & 0b00001111),
					static_cast<MemoryByte>(
							(registerName0 & 0b00001111) | ((registerName1 & 0b00001111) << 4)
					)
			);
		}

		Assembler& Assembler::debug() {
			return add(Opcode::DEBUG);
		}

		Assembler& Assembler::halt() {
			return add(Opcode::HALT);
		}

	}
}