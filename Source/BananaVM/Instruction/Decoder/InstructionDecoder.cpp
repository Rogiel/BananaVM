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
#include "../LoadInstruction.h"
#include "../HaltInstruction.h"
#include "../DebugInstruction.h"
#include "../StoreInstruction.h"

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
								RegisterName sourceRegisterName = static_cast<RegisterName>(arg1 & 0b00001111);

								return std::unique_ptr<Instruction>(
										new LoadInstruction(LoadInstruction::Type::REGISTER, registerName, 0, 0, sourceRegisterName));
							}

							case LoadInstruction::Type::ADDRESS: {
								MemoryByte arg1 = memoryResolver[pc++];
								MemoryByte arg2 = memoryResolver[pc++];

								MemoryAddress address = arg2 | arg1 << 8;
								return std::unique_ptr<Instruction>(
										new LoadInstruction(LoadInstruction::Type::ADDRESS, registerName, address, 0, 0));
							}
						}
					}

					case Opcode::STORE: {
						MemoryByte arg0 = memoryResolver[pc++];
						MemoryByte arg1 = memoryResolver[pc++];
						MemoryByte arg2 = memoryResolver[pc++];

						RegisterName registerName = static_cast<RegisterName>(arg0 & 0b00001111);
						MemoryAddress address = arg2 | arg1 << 8;

						return std::unique_ptr<Instruction>(new StoreInstruction(registerName, address));
					}

					case Opcode::HALT:
						return std::unique_ptr<Instruction>(new HaltInstruction());

					case Opcode::DEBUG:
						return std::unique_ptr<Instruction>(new DebugInstruction());

					default:
						throw std::string("Unknown opcode!!!");
				}
			}
		}
	}
}