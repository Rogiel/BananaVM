//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#include <string>

#include "ProcessorThread.h"
#include "Memory/MemoryResolver.h"
#include "Instruction/Decoder/InstructionDecoder.h"

namespace BananaVM {

	ProcessorThread::ProcessorThread(Memory::MemoryResolver& memoryResolver) : _memoryResolver(memoryResolver) {}

	void ProcessorThread::step() {
		Instruction::Decoder::InstructionDecoder instructionDecoder;
		auto instruction = instructionDecoder.decode(_context, _memoryResolver);
		if(instruction) {
			instruction->perform(_context);
		} else {
			throw std::string("Instruction decoder returned a invalid instruction");
		}
	}

	void ProcessorThread::run() {
		while(true) {
			step();
			if(_context.isHalted()) {
				return;
			}
		}
	}

}