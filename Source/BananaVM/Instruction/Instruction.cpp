//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#include "Instruction.h"

namespace BananaVM {
	namespace Instruction {

		UnaryInstruction::UnaryInstruction(RegisterName register0) :
				_register0(register0) { }

		BinaryInstruction::BinaryInstruction(RegisterName register0, RegisterName register1) :
				_register0(register0), _register1(register1) { }

	}
}