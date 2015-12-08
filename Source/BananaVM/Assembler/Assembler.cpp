//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include "Assembler.h"
#include "../Instruction/MemoryInstructions.h"

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

		Assembler& Assembler::mark(MemoryAddress& address) {
			address = _pointer;
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
							(static_cast<MemoryByte>(Instruction::LoadInstruction::Type::REGISTER) & 0b00001111) << 4),
					static_cast<MemoryByte>(address & 0b00001111)
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

		Assembler& Assembler::add(RegisterName registerName0, RegisterName registerName1) {
			return add(
					Opcode::ADD,
					static_cast<MemoryByte>(
							(registerName1 & 0b00001111) | ((registerName0 & 0b00001111) << 4)
					)
			);
		}

		Assembler& Assembler::subtract(RegisterName registerName0, RegisterName registerName1) {
			return add(
					Opcode::SUBTRACT,
					static_cast<MemoryByte>(
							(registerName1 & 0b00001111) | ((registerName0 & 0b00001111) << 4)
					)
			);
		}

		Assembler& Assembler::multiply(RegisterName registerName0, RegisterName registerName1) {
			return add(
					Opcode::MULTIPLY,
					static_cast<MemoryByte>(
							(registerName1 & 0b00001111) | ((registerName0 & 0b00001111) << 4)
					)
			);
		}

		Assembler& Assembler::divide(RegisterName registerName0, RegisterName registerName1) {
			return add(
					Opcode::DIVIDE,
					static_cast<MemoryByte>(
							(registerName1 & 0b00001111) | ((registerName0 & 0b00001111) << 4)
					)
			);
		}

		Assembler& Assembler::debug() {
			return add(Opcode::DEBUG);
		}

		Assembler& Assembler::halt() {
			return add(Opcode::HALT);
		}

		Assembler& Assembler::bitwiseAnd(RegisterName registerName0, RegisterName registerName1) {
			return add(
					Opcode::AND,
					static_cast<MemoryByte>(
							(registerName1 & 0b00001111) | ((registerName0 & 0b00001111) << 4)
					)
			);
		}

		Assembler& Assembler::bitwiseOr(RegisterName registerName0, RegisterName registerName1) {
			return add(
					Opcode::OR,
					static_cast<MemoryByte>(
							(registerName1 & 0b00001111) | ((registerName0 & 0b00001111) << 4)
					)
			);
		}

		Assembler& Assembler::bitwiseNand(RegisterName registerName0, RegisterName registerName1) {
			return add(
					Opcode::NAND,
					static_cast<MemoryByte>(
							(registerName1 & 0b00001111) | ((registerName0 & 0b00001111) << 4)
					)
			);
		}

		Assembler& Assembler::bitwiseXor(RegisterName registerName0, RegisterName registerName1) {
			return add(
					Opcode::XOR,
					static_cast<MemoryByte>(
							(registerName1 & 0b00001111) | ((registerName0 & 0b00001111) << 4)
					)
			);
		}

		Assembler& Assembler::bitwiseNot(RegisterName registerName0) {
			return add(
					Opcode::NOT,
					static_cast<MemoryByte>(registerName0 & 0b00001111)
			);
		}

		Assembler& Assembler::bitwiseRightShift(RegisterName registerName0, RegisterName registerName1) {
			return add(
					Opcode::RIGHT_SHIFT,
					static_cast<MemoryByte>(
							(registerName1 & 0b00001111) | ((registerName0 & 0b00001111) << 4)
					)
			);
		}

		Assembler& Assembler::bitwiseLeftShift(RegisterName registerName0, RegisterName registerName1) {
			return add(
					Opcode::LEFT_SHIFT,
					static_cast<MemoryByte>(
							(registerName1 & 0b00001111) | ((registerName0 & 0b00001111) << 4)
					)
			);
		}

		Assembler& Assembler::jump(MemoryAddress memoryAddress) {
			return add(
					Opcode::JUMP,
					static_cast<MemoryByte>((memoryAddress & 0xFF00) >> 8),
					static_cast<MemoryByte>(memoryAddress & 0x00FF)
			);
		}

		Assembler& Assembler::jumpIf(RegisterName registerName, MemoryAddress memoryAddress) {
			return add(
					Opcode::CONDITIONAL_JUMP,
					static_cast<MemoryByte>(registerName & 0b00001111),
					static_cast<MemoryByte>((memoryAddress & 0xFF00) >> 8),
					static_cast<MemoryByte>(memoryAddress & 0x00FF)
			);
		}

		Assembler& Assembler::jumpIfCarry(MemoryAddress memoryAddress) {
			return add(
					Opcode::JUMP_IF_CARRY,
					static_cast<MemoryByte>((memoryAddress & 0xFF00) >> 8),
					static_cast<MemoryByte>(memoryAddress & 0x00FF)
			);
		}

		Assembler& Assembler::greaterThan(RegisterName registerName0, RegisterName registerName1) {
			return add(
					Opcode::GREATER_THAN,
					static_cast<MemoryByte>(
							(registerName1 & 0b00001111) | ((registerName0 & 0b00001111) << 4)
					)
			);
		}

		Assembler& Assembler::greaterOrEqualThan(RegisterName registerName0, RegisterName registerName1) {
			return add(
					Opcode::GREATER_OR_EQUAL_THAN,
					static_cast<MemoryByte>(
							(registerName1 & 0b00001111) | ((registerName0 & 0b00001111) << 4)
					)
			);
		}

		Assembler& Assembler::lessThan(RegisterName registerName0, RegisterName registerName1) {
			return add(
					Opcode::LESS_THAN,
					static_cast<MemoryByte>(
							(registerName1 & 0b00001111) | ((registerName0 & 0b00001111) << 4)
					)
			);
		}

		Assembler& Assembler::lessOrEqualThan(RegisterName registerName0, RegisterName registerName1) {
			return add(
					Opcode::LESS_OR_EQUAL_THAN,
					static_cast<MemoryByte>(
							(registerName1 & 0b00001111) | ((registerName0 & 0b00001111) << 4)
					)
			);
		}

		Assembler& Assembler::equal(RegisterName registerName0, RegisterName registerName1) {
			return add(
					Opcode::EQUAL,
					static_cast<MemoryByte>(
							(registerName1 & 0b00001111) | ((registerName0 & 0b00001111) << 4)
					)
			);
		}

		Assembler& Assembler::notEqual(RegisterName registerName0, RegisterName registerName1) {
			return add(
					Opcode::NOT_EQUAL,
					static_cast<MemoryByte>(
							(registerName1 & 0b00001111) | ((registerName0 & 0b00001111) << 4)
					)
			);
		}

		Assembler& Assembler::writeIO(RegisterName registerName) {
			return add(
					Opcode::WRITE_IO,
					static_cast<MemoryByte>(
							((registerName & 0b00001111) << 4)
					)
			);
		}

		Assembler& Assembler::readIO(RegisterName registerName) {
			return add(
					Opcode::READ_IO,
					static_cast<MemoryByte>(
							((registerName & 0b00001111) << 4)
					)
			);
		}

		void Assembler::printMemoryArray() {
			for(auto i = 0; i<_pointer; ++i) {
				std::bitset<8> bitset(_memoryStore[i]);
				std::cout << "\"" << bitset << "\"," << std::endl;
			}
		}
	}
}