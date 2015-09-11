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
			.loadConstant(0, 100)
			.loadConstant(1, 800)
			.add(0, 1, 8)
			.subtract(1, 0, 9)
			.store(0, 3000)
			.loadAddress(1, 1024)
			.loadRegister(2, 0)
			.loadAddress(3, 3000)
			.debug()
			.halt();

	// create some static data
	memoryStore.load({1, 0}, 1024);

	// creates a new thread and run it
	ProcessorThread thread(memoryResolver);
	thread.run();

	// if we reach this point, HALT was possibly called
	std::cout << "Processor is halted. Ending VM..." << std::endl;

	return 0;
}