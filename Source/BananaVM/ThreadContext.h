//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#pragma once

#include "Config.h"
#include "Types.h"

namespace BananaVM {

	/**
	 * The processor context stores and maintains the internal processor state
	 */
	class ThreadContext {
	private:
		/**
		 * The processor program counter
		 */
		Register _programCounter = 0;

		/**
		 * The processor internal registers
		 */
		Register _registers[BananaVM::MAX_REGISTER_COUNT] = {0};

		bool _halted = 0;

	public:
		/**
		 * @return the program counter
		 */
		Register& getProgramCounter() {
			return _programCounter;
		}

		/**
		 * @return the program counter
		 */
		const Register& getProgramCounter() const {
			return _programCounter;
		}

		/**
		 * Sets the program counter
		 *
		 * @param programCounter the new program counter to set
		 */
		void setProgramCounter(const Register& programCounter) {
			_programCounter = programCounter;
		}

		/**
		 * @param reg the register to return
		 *
		 * @return the register represented by "reg"
		 */
		Register& getRegister(RegisterName reg) {
			return _registers[reg];
		}

		/**
		 * @param reg the register to return
		 *
		 * @return the register represented by "reg"
		 */
		const Register& getRegister(RegisterName reg) const {
			return _registers[reg];
		}

		/**
		 * Sets a register
		 *
		 * @param reg the register to change value
		 * @param aRegister the new register value
		 */
		void setRegister(RegisterName reg, const Register& aRegister) {
			_registers[reg] = aRegister;
		}

		bool isHalted() const {
			return _halted;
		}

		void setHalted(bool halted) {
			_halted = halted;
		}
	};

}
