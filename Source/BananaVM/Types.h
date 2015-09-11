//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#pragma once

#include <cstdint>

namespace BananaVM {

	// ----------------------------------------------------
	// -- Register
	// ----------------------------------------------------

	using RegisterName = std::uint8_t;

	/**
	 * The register type
	 */
	using Register = std::uint16_t;


	// ----------------------------------------------------
	// -- Memory
	// ----------------------------------------------------

	/**
	 * A memory byte
	 */
	using MemoryByte = std::uint8_t;

	/**
	 * A pointer that points to a block of memory
	 */
	using MemoryPointer = MemoryByte*;

	/**
	 * The memory address type
	 */
	using MemoryAddress = std::uint16_t;

	/**
	 * A type representing the length of a memory address
	 */
	using MemoryLength = std::uint16_t;

}

