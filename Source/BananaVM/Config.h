//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#pragma once

#include <cstdint>

#include "Types.h"

namespace BananaVM {

	/**
	 * The maximum number of registers available on the processor
	 */
	constexpr std::uint8_t MAX_REGISTER_COUNT = 16;

	constexpr RegisterName REGISTER_0 = 0;
	constexpr RegisterName REGISTER_1 = 1;
	constexpr RegisterName REGISTER_2 = 2;
	constexpr RegisterName REGISTER_3 = 3;
	constexpr RegisterName REGISTER_4 = 4;
	constexpr RegisterName REGISTER_5 = 5;
	constexpr RegisterName REGISTER_6 = 6;
	constexpr RegisterName REGISTER_7 = 7;
	constexpr RegisterName REGISTER_8 = 8;
	constexpr RegisterName REGISTER_9 = 9;
	constexpr RegisterName REGISTER_10 = 10;
	constexpr RegisterName REGISTER_11 = 11;
	constexpr RegisterName REGISTER_12 = 12;
	constexpr RegisterName REGISTER_13 = 13;
	constexpr RegisterName REGISTER_ACCUMULATOR = 14;
	constexpr RegisterName REGISTER_CARRY = 15;
}

