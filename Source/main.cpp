//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#include <iostream>

#include "BananaVM/Memory/MemoryStore.h"
#include "BananaVM/ProcessorThread.h"
#include "BananaVM/Assembler/Assembler.h"

int main() {
	using namespace BananaVM;

	// allocates 8kb of memory
	Memory::MemoryStore memoryStore(8 * 1024);

	// creates the memory resolver attached to the store
	Memory::MemoryResolver memoryResolver(memoryStore);

	// assembles a very simple program
	Assembler::Assembler(memoryStore)
			.debug()
			.loadConstant(0, 100)
			.loadAddress(1, 1)
			.loadRegister(2, 0)
			.debug()
			.halt();

	// creates a new thread and run it
	ProcessorThread thread(memoryResolver);
	thread.run();

	// if we reach this point, HALT was possibly called
	std::cout << "Processor is halted. Ending VM..." << std::endl;

	return 0;
}