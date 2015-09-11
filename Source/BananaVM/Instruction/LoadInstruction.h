//
//  BananaVM - A Virtual Machine implementation for BananaCore
//
//  Created by Rogiel Sulzbach.
//  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
//

#pragma once

#include "Instruction.h"
#include "../Types.h"

namespace BananaVM {
	namespace Instruction {

		/**
		 * Implements the LOAD instruction
		 */
		class LoadInstruction : public Instruction {
		public:
			enum class Type {
				REGISTER = 0b0000,
				ADDRESS = 0b0001,
				CONSTANT = 0b0010
			};

		private:
			Type _type;
			RegisterName _registerName;


			MemoryAddress _memoryAddress;
			Register _constant;
			RegisterName _sourceRegisterName;

		public:
			LoadInstruction(Type type, RegisterName registerName, MemoryAddress memoryAddress, Register constant, RegisterName sourceRegisterName);

		public:
			/**
			 * Executes the instruction
			 *
			 * @param context the processor context
			 */
			virtual void perform(ProcessorThread& thread) override;

		};
	}
}
