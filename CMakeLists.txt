cmake_minimum_required(VERSION 3.22)
project(Pong-Game)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
set(SOURCES 
	src/main.cpp
	src/Ball.cpp
	src/Ball.h
	src/Paddle.cpp
	src/Paddle.h
	src/GameManager.cpp
	src/GameManager.h)
add_executable(game ${SOURCES})
