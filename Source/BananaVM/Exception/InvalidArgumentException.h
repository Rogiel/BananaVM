//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#pragma once

#include "VMException.h"

namespace BananaVM {
	namespace Exception {

		class InvalidArgumentException : public VMException { };

	}
}
