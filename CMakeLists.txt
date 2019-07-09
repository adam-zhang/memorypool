cmake_minimum_required(VERSION 2.8)
project(memorypool)
set(sources main.cpp
	MemoryPool.cpp)
add_executable(${PROJECT_NAME} ${sources})
