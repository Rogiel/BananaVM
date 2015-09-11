//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#pragma once

#include "Memory/MemoryStore.h"
#include "ThreadContext.h"
#include "Memory/MemoryResolver.h"

namespace BananaVM {

	/**
	 * Represents a running thread on the processor
	 */
	class ProcessorThread {
	private:
		/**
		 * The thread context
		 */
		ThreadContext _context;

		/**
		 * The thread memory resolver
		 */
		Memory::MemoryResolver& _memoryResolver;

	public:
		/**
		 * Creates a new processor thread with a memory resolver
		 *
		 * @param memoryResolver the memory resolver
		 */
		ProcessorThread(Memory::MemoryResolver& memoryResolver);

	public:
		/**
		 * Runs a single intruction
		 */
		void step();

		/**
		 * Runs the processor until HALT is called
		 */
		void run();

	};

}



