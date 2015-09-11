//
//  Juice - Peer to Peer Networking library
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#include "Assembler.h"

namespace BananaVM {
	namespace Assembler {


		Assembler::Assembler(Memory::MemoryStore& memoryStore) : _memoryStore(memoryStore), _pointer(0) {}

		Assembler& Assembler::add(Opcode opcode) {
			_memoryStore[_pointer++] = static_cast<MemoryByte>(opcode);
			return *this;
		}

		Assembler& Assembler::loadConstant(RegisterName registerName, Register constant) {
			return add(Opcode::LOAD);
		}

		Assembler& Assembler::loadAddress(RegisterName registerName, MemoryAddress address) {
			return add(Opcode::LOAD);
		}

		Assembler& Assembler::debug() {
			return add(Opcode::DEBUG);
		}

		Assembler& Assembler::halt() {
			return add(Opcode::HALT);
		}
	}
}