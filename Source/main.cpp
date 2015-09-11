#include <iostream>

#include "BananaVM/Memory/MemoryStore.h"
#include "BananaVM/ProcessorThread.h"
#include "BananaVM/Assembler/Assembler.h"

int main() {
	using namespace BananaVM;

	Memory::MemoryStore memoryStore(8 * 1024);
	Memory::MemoryResolver memoryResolver(memoryStore);

	Assembler::Assembler(memoryStore)
			.loadConstant(0, 0)
			.loadConstant(0, 0)
			.debug()
			.halt();

	ProcessorThread thread(memoryResolver);
	thread.run();

	return 0;
}