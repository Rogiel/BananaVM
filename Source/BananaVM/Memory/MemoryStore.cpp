//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#include "MemoryStore.h"

namespace BananaVM {
	namespace Memory {

		MemoryStore::MemoryStore(MemoryLength size) : _data(new MemoryByte[size]) {}

		MemoryStore::~MemoryStore() {
			if(_data) {
				delete[] _data;
			}
		}

		const MemoryByte& MemoryStore::operator[](const MemoryAddress address) const {
			return *(_data + address);
		}

		MemoryByte& MemoryStore::operator[](const MemoryAddress address) {
			return *(_data + address);
		}
	}
}