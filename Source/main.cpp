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

	// defines the factorial operand
	Register factorial = 8;

	// the memory address to jump when continuing the loop
	MemoryAddress loopAddress;

	// assembles a program that computes the factorial of a number
	Assembler::Assembler(memoryStore)
//			.loadConstant(REGISTER_0, factorial)
			.readIO(REGISTER_0)
			.loadConstant(REGISTER_1, 0)
			.loadConstant(REGISTER_2, 1)
			.loadConstant(REGISTER_3, 1)

			.mark(loopAddress)

			.multiply(REGISTER_2, REGISTER_0)
			.loadRegister(REGISTER_2, REGISTER_ACCUMULATOR)

			.subtract(REGISTER_0, REGISTER_3)
			.loadRegister(REGISTER_0, REGISTER_ACCUMULATOR)

			.notEqual(REGISTER_0, REGISTER_1)
			.jumpIfCarry(loopAddress)

			.writeIO(REGISTER_2)

			//.debug()
			//.halt()
			.jump(0)
			.printMemoryArray();



	// creates a new thread and run it
	ProcessorThread thread(memoryResolver);
	thread.run();

	// if we reach this point, HALT was possibly called
	std::cout << "Processor is halted. Ending VM..." << std::endl;
	std::cout << factorial << "! = " << thread.getContext().getRegister(REGISTER_2) << std::endl;

	return 0;
}