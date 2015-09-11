//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#pragma once

#include <memory>

#include "../Instruction.h"
#include "../../ThreadContext.h"
#include "../../Memory/MemoryResolver.h"

namespace BananaVM {
	namespace Instruction {
		namespace Decoder {

			class InstructionDecoder {
			public:
				/**
				 * Decodes a instruction
				 *
				 * @param context the processor context
				 * @param memoryResolver the processor memory resolver
				 */
				std::unique_ptr<Instruction> decode(ThreadContext& context, Memory::MemoryResolver& memoryResolver);

			private:
				std::tuple<RegisterName, RegisterName> decodeBinaryInstruction(MemoryByte byte);
				MemoryAddress decodeAddress(MemoryByte byte0, MemoryByte byte1);

			};

		}
	}
}