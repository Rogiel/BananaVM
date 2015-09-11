//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#include <string>
#include <iostream>

#include "../../Opcode.h"

#include "InstructionDecoder.h"
#include "../MemoryInstructions.h"
#include "../ControlInstructions.h"
#include "../ArithmeticInstructions.h"
#include "../BitwiseInstructions.h"
#include "../BranchingInstructions.h"
#include "../ComparisionInstructions.h"

namespace BananaVM {
	namespace Instruction {
		namespace Decoder {


			std::unique_ptr<Instruction> InstructionDecoder::decode(ThreadContext& context,
														  Memory::MemoryResolver& memoryResolver) {

				auto& pc = context.getProgramCounter();
				MemoryByte opcodeByte = memoryResolver[pc++];
				Opcode opcode = static_cast<Opcode>(opcodeByte);

				switch(opcode) {
					case Opcode::LOAD: {
						MemoryByte arg0 = memoryResolver[pc++];

						MemoryByte typeNumeric = static_cast<RegisterName>((arg0 & 0b11110000) >> 4);
						RegisterName registerName = static_cast<RegisterName>(arg0 & 0b00001111);

						LoadInstruction::Type type = static_cast<LoadInstruction::Type>(typeNumeric);

						switch(type) {
							case LoadInstruction::Type::CONSTANT: {
								MemoryByte arg1 = memoryResolver[pc++];
								MemoryByte arg2 = memoryResolver[pc++];

								Register value = arg2 | arg1 << 8;
								return std::unique_ptr<Instruction>(
										new LoadInstruction(LoadInstruction::Type::CONSTANT, registerName, 0, value, 0));
							}

							case LoadInstruction::Type::REGISTER: {
								MemoryByte arg1 = memoryResolver[pc++];

								RegisterName sourceRegisterName;
								std::tie(std::ignore, sourceRegisterName) = decodeBinaryInstruction(arg1);

								return std::unique_ptr<Instruction>(
										new LoadInstruction(LoadInstruction::Type::REGISTER, registerName, 0, 0, sourceRegisterName));
							}

							case LoadInstruction::Type::ADDRESS: {
								MemoryByte arg1 = memoryResolver[pc++];
								MemoryByte arg2 = memoryResolver[pc++];

								MemoryAddress address = decodeAddress(arg1, arg2);
								return std::unique_ptr<Instruction>(
										new LoadInstruction(LoadInstruction::Type::ADDRESS, registerName, address, 0, 0));
							}
						}
					}

					case Opcode::STORE: {
						MemoryByte arg0 = memoryResolver[pc++];
						MemoryByte arg1 = memoryResolver[pc++];
						MemoryByte arg2 = memoryResolver[pc++];

						RegisterName registerName;
						std::tie(std::ignore, registerName) = decodeBinaryInstruction(arg0);
						MemoryAddress address = decodeAddress(arg1, arg2);

						return std::unique_ptr<Instruction>(new StoreInstruction(registerName, address));
					}

					// -------------------------------------------------------------------------------------------------

					case Opcode::ADD: {
						MemoryByte arg0 = memoryResolver[pc++];

						RegisterName registerName0;
						RegisterName registerName1;
						std::tie(registerName0, registerName1) = decodeBinaryInstruction(arg0);

						return std::unique_ptr<Instruction>(new AddInstruction(registerName0, registerName1));
					}

					case Opcode::SUBTRACT: {
						MemoryByte arg0 = memoryResolver[pc++];

						RegisterName registerName0;
						RegisterName registerName1;
						std::tie(registerName0, registerName1) = decodeBinaryInstruction(arg0);

						return std::unique_ptr<Instruction>(new SubtractInstruction(registerName0, registerName1));
					}

					case Opcode::MULTIPLY: {
						MemoryByte arg0 = memoryResolver[pc++];

						RegisterName registerName0;
						RegisterName registerName1;
						std::tie(registerName0, registerName1) = decodeBinaryInstruction(arg0);

						return std::unique_ptr<Instruction>(new MultiplyInstruction(registerName0, registerName1));
					}

					case Opcode::DIVIDE: {
						MemoryByte arg0 = memoryResolver[pc++];

						RegisterName registerName0;
						RegisterName registerName1;
						std::tie(registerName0, registerName1) = decodeBinaryInstruction(arg0);

						return std::unique_ptr<Instruction>(new DivideInstruction(registerName0, registerName1));
					}

					// -------------------------------------------------------------------------------------------------

					case Opcode::JUMP: {
						MemoryByte arg0 = memoryResolver[pc++];
						MemoryByte arg1 = memoryResolver[pc++];

						MemoryAddress memoryAddress = decodeAddress(arg0, arg1);

						return std::unique_ptr<Instruction>(new JumpInstruction(memoryAddress));
					}

					case Opcode::CONDITIONAL_JUMP: {
						MemoryByte arg0 = memoryResolver[pc++];
						MemoryByte arg1 = memoryResolver[pc++];
						MemoryByte arg2 = memoryResolver[pc++];

						RegisterName registerName;

						std::tie(std::ignore, registerName) = decodeBinaryInstruction(arg0);
						MemoryAddress memoryAddress = decodeAddress(arg1, arg2);

						return std::unique_ptr<Instruction>(new ConditionalJumpInstruction(registerName, memoryAddress));
					}

					case Opcode::JUMP_IF_CARRY: {
						MemoryByte arg0 = memoryResolver[pc++];
						MemoryByte arg1 = memoryResolver[pc++];

						MemoryAddress memoryAddress = decodeAddress(arg0, arg1);

						return std::unique_ptr<Instruction>(new JumpIfCarryInstruction(memoryAddress));
					}

					// -------------------------------------------------------------------------------------------------

					case Opcode::AND: {
						MemoryByte arg0 = memoryResolver[pc++];

						RegisterName registerName0;
						RegisterName registerName1;
						std::tie(registerName0, registerName1) = decodeBinaryInstruction(arg0);

						return std::unique_ptr<Instruction>(new AndInstruction(registerName0, registerName1));
					}

					case Opcode::OR: {
						MemoryByte arg0 = memoryResolver[pc++];

						RegisterName registerName0;
						RegisterName registerName1;
						std::tie(registerName0, registerName1) = decodeBinaryInstruction(arg0);

						return std::unique_ptr<Instruction>(new OrInstruction(registerName0, registerName1));
					}

					case Opcode::NAND: {
						MemoryByte arg0 = memoryResolver[pc++];

						RegisterName registerName0;
						RegisterName registerName1;
						std::tie(registerName0, registerName1) = decodeBinaryInstruction(arg0);

						return std::unique_ptr<Instruction>(new NandInstruction(registerName0, registerName1));
					}

					case Opcode::XOR: {
						MemoryByte arg0 = memoryResolver[pc++];

						RegisterName registerName0;
						RegisterName registerName1;
						std::tie(registerName0, registerName1) = decodeBinaryInstruction(arg0);

						return std::unique_ptr<Instruction>(new XorInstruction(registerName0, registerName1));
					}

					case Opcode::NOT: {
						MemoryByte arg0 = memoryResolver[pc++];

						RegisterName registerName0;
						std::tie(std::ignore, registerName0) = decodeBinaryInstruction(arg0);

						return std::unique_ptr<Instruction>(new NotInstruction(registerName0));
					}

					case Opcode::RIGHT_SHIFT: {
						MemoryByte arg0 = memoryResolver[pc++];

						RegisterName registerName0;
						RegisterName registerName1;
						std::tie(registerName0, registerName1) = decodeBinaryInstruction(arg0);

						return std::unique_ptr<Instruction>(new RightShiftInstruction(registerName0, registerName1));
					}

					case Opcode::LEFT_SHIFT: {
						MemoryByte arg0 = memoryResolver[pc++];

						RegisterName registerName0;
						RegisterName registerName1;
						std::tie(registerName0, registerName1) = decodeBinaryInstruction(arg0);

						return std::unique_ptr<Instruction>(new LeftShiftInstruction(registerName0, registerName1));
					}

					// -------------------------------------------------------------------------------------------------

					case Opcode::GREATER_THAN: {
						MemoryByte arg0 = memoryResolver[pc++];

						RegisterName registerName0;
						RegisterName registerName1;
						std::tie(registerName0, registerName1) = decodeBinaryInstruction(arg0);

						return std::unique_ptr<Instruction>(new GreaterThanInstruction(registerName0, registerName1));
					}

					case Opcode::GREATER_OR_EQUAL_THAN: {
						MemoryByte arg0 = memoryResolver[pc++];

						RegisterName registerName0;
						RegisterName registerName1;
						std::tie(registerName0, registerName1) = decodeBinaryInstruction(arg0);

						return std::unique_ptr<Instruction>(new GreaterOrEqualThanInstruction(registerName0, registerName1));
					}

					case Opcode::LESS_THAN: {
						MemoryByte arg0 = memoryResolver[pc++];

						RegisterName registerName0;
						RegisterName registerName1;
						std::tie(registerName0, registerName1) = decodeBinaryInstruction(arg0);

						return std::unique_ptr<Instruction>(new LessThanInstruction(registerName0, registerName1));
					}

					case Opcode::LESS_OR_EQUAL_THAN: {
						MemoryByte arg0 = memoryResolver[pc++];

						RegisterName registerName0;
						RegisterName registerName1;
						std::tie(registerName0, registerName1) = decodeBinaryInstruction(arg0);

						return std::unique_ptr<Instruction>(new LessOrEqualThanInstruction(registerName0, registerName1));
					}

					case Opcode::EQUAL: {
						MemoryByte arg0 = memoryResolver[pc++];

						RegisterName registerName0;
						RegisterName registerName1;
						std::tie(registerName0, registerName1) = decodeBinaryInstruction(arg0);

						return std::unique_ptr<Instruction>(new EqualInstruction(registerName0, registerName1));
					}

					case Opcode::NOT_EQUAL: {
						MemoryByte arg0 = memoryResolver[pc++];

						RegisterName registerName0;
						RegisterName registerName1;
						std::tie(registerName0, registerName1) = decodeBinaryInstruction(arg0);

						return std::unique_ptr<Instruction>(new NotEqualInstruction(registerName0, registerName1));
					}

					// -------------------------------------------------------------------------------------------------


					case Opcode::HALT:
						return std::unique_ptr<Instruction>(new HaltInstruction());

					case Opcode::DEBUG:
						return std::unique_ptr<Instruction>(new DebugInstruction());

//					default:
//						throw std::string("Unknown opcode!!!");
				}
			}

			std::tuple<RegisterName, RegisterName> InstructionDecoder::decodeBinaryInstruction(MemoryByte byte) {
				return std::make_tuple(
						static_cast<RegisterName>((byte & 0b11110000) >> 4),
						static_cast<RegisterName>(byte & 0b00001111)
				);
			}

			MemoryAddress InstructionDecoder::decodeAddress(MemoryByte byte0, MemoryByte byte1) {
				return (byte1 | byte0 << 8);
			}
		}
	}
}