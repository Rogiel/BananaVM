//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#include <string>

#include "../../Opcode.h"

#include "InstructionDecoder.h"
#include "../LoadInstruction.h"
#include "../HaltInstruction.h"

namespace BananaVM {
	namespace Instruction {
		namespace Decoder {


			std::unique_ptr<Instruction> InstructionDecoder::decode(ThreadContext& context,
														  Memory::MemoryResolver& memoryResolver) {

				auto& pc = context.getProgramCounter();
				MemoryByte opcodeByte = memoryResolver[pc];
				Opcode opcode = static_cast<Opcode>(opcodeByte);

				pc++;
				switch(opcode) {
					case Opcode::LOAD:
						return std::unique_ptr<Instruction>(new LoadInstruction());

					case Opcode::HALT:
						return std::unique_ptr<Instruction>(new HaltInstruction());

					default:
						throw std::string("Unknown opcode!!!");
				}
			}
		}
	}
}