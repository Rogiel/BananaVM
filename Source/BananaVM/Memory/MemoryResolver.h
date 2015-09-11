//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#pragma once

#include "MemoryStore.h"

namespace BananaVM {
	namespace Memory {

		/**
		 * The memory resolver is responsible for mapping the real DATA memory and IO into a virtual memory space
		 */
		class MemoryResolver {
			// TODO implement IO
			// TODO implement memory "mounting"

		private:
			/**
			 * The physical memory store
			 */
			MemoryStore& _store;

		public:
			/**
			 * Creates a new memory resolver from a existing store
			 */
			MemoryResolver(MemoryStore& store);

		public:
			/**
			 * Returns the byte at the given address
			 *
			 * @param address the address to return the byte from
			 * @return a const reference to the byte
			 */
			const MemoryByte& operator[](const MemoryAddress address) const;

			/**
			 * Returns the byte at the given address
			 *
			 * @param address the address to return the byte from
			 * @return a reference to the byte
			 */
			MemoryByte& operator[](const MemoryAddress address);

		};

	}
}


