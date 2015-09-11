//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#include "MemoryResolver.h"

namespace BananaVM {
	namespace Memory {

		MemoryResolver::MemoryResolver(MemoryStore& store) : _store(store) {}

		const MemoryByte& MemoryResolver::operator[](const MemoryAddress address) const {
			return _store[address];
		}

		MemoryByte& MemoryResolver::operator[](const MemoryAddress address) {
			return _store[address];
		}
	}
}