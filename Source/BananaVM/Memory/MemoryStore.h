//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#pragma once

#include <memory>
#include "../Types.h"

namespace BananaVM {
	namespace Memory {

		class MemoryStore {
		private:
			MemoryPointer _data;

		public:
			/**
			 * Creates a new memory store by allocating at least "size" contiguous bytes
			 *
			 * @param size the memory block size
			 */
			MemoryStore(MemoryLength size);

			/**
			 * Destroys the memory store and frees any allocated memory
			 */
			~MemoryStore();

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

		public:
			template<std::size_t N>
			void load(MemoryByte bytes[N], MemoryAddress starting = 0) {
				for(auto i = starting; i<bytes; i++) {
					(*this)[i] = bytes[i];
				}
			}

			void load(std::initializer_list<MemoryByte> bytes, MemoryAddress starting = 0) {
				MemoryAddress i = starting;
				for(MemoryByte byte : bytes) {
					(*this)[i++] = byte;
				}
			}
		};

	}
}

