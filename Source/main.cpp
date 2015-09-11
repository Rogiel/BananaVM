#include <iostream>

#include "BananaVM/Memory/MemoryStore.h"
#include "BananaVM/ProcessorThread.h"

int main() {
	BananaVM::Memory::MemoryStore memoryStore(8 * 1024);
	BananaVM::Memory::MemoryResolver memoryResolver(memoryStore);

	memoryStore[0] = 0x00;
	memoryStore[1] = 0xfe;

	BananaVM::ProcessorThread thread(memoryResolver);
	thread.run();

	return 0;
}