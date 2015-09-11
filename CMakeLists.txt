cmake_minimum_required(VERSION 3.3)
project(BananaVM)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        Source/main.cpp
        Source/BananaVM/Opcode.h
        Source/BananaVM/ThreadContext.cpp
        Source/BananaVM/ThreadContext.h
        Source/BananaVM/Instruction/Instruction.cpp
        Source/BananaVM/Instruction/Instruction.h
        Source/BananaVM/Instruction/LoadInstruction.cpp
        Source/BananaVM/Instruction/LoadInstruction.h
        Source/BananaVM/Config.h Source/BananaVM/Memory/MemoryResolver.cpp Source/BananaVM/Memory/MemoryResolver.h Source/BananaVM/Memory/MemoryStore.cpp Source/BananaVM/Memory/MemoryStore.h Source/BananaVM/Types.h Source/BananaVM/ProcessorThread.cpp Source/BananaVM/ProcessorThread.h Source/BananaVM/Instruction/Decoder/InstructionDecoder.cpp Source/BananaVM/Instruction/Decoder/InstructionDecoder.h Source/BananaVM/Instruction/HaltInstruction.cpp Source/BananaVM/Instruction/HaltInstruction.h)
add_executable(BananaVM ${SOURCE_FILES})
target_compile_features(BananaVM PRIVATE cxx_range_for)

