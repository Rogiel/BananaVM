##
##  BananaVM - A Virtual Machine implementation for BananaCore
##
##  Created by Rogiel Sulzbach.
##  Copyright (c) 2014-2015 Rogiel Sulzbach. All rights reserved.
##

cmake_minimum_required(VERSION 3.3)
project(BananaVM)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        Source/BananaVM/Config.h
        Source/BananaVM/Types.h
        Source/BananaVM/Opcode.h

        Source/main.cpp

        Source/BananaVM/ThreadContext.cpp
        Source/BananaVM/ThreadContext.h

        Source/BananaVM/Instruction/Instruction.cpp
        Source/BananaVM/Instruction/Instruction.h

        Source/BananaVM/Instruction/MemoryInstructions.cpp
        Source/BananaVM/Instruction/MemoryInstructions.h

        Source/BananaVM/Instruction/ArithmeticInstructions.cpp
        Source/BananaVM/Instruction/ArithmeticInstructions.h

        Source/BananaVM/Instruction/BitwiseInstructions.cpp
        Source/BananaVM/Instruction/BitwiseInstructions.h

        Source/BananaVM/Instruction/ComparisionInstructions.cpp
        Source/BananaVM/Instruction/ComparisionInstructions.h

        Source/BananaVM/Instruction/BranchingInstructions.cpp
        Source/BananaVM/Instruction/BranchingInstructions.h

        Source/BananaVM/Instruction/ControlInstructions.cpp
        Source/BananaVM/Instruction/ControlInstructions.h

        Source/BananaVM/Memory/MemoryResolver.cpp
        Source/BananaVM/Memory/MemoryResolver.h

        Source/BananaVM/Memory/MemoryStore.cpp
        Source/BananaVM/Memory/MemoryStore.h

        Source/BananaVM/ProcessorThread.cpp
        Source/BananaVM/ProcessorThread.h

        Source/BananaVM/Instruction/Decoder/InstructionDecoder.cpp
        Source/BananaVM/Instruction/Decoder/InstructionDecoder.h

        Source/BananaVM/Assembler/Assembler.cpp
        Source/BananaVM/Assembler/Assembler.h

        Source/BananaVM/Exception/VMException.h
        Source/BananaVM/Exception/InvalidArgumentException.h
)
add_executable(BananaVM ${SOURCE_FILES})
target_compile_features(BananaVM PRIVATE cxx_range_for)

