cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD_REQUIRED True)

project("prototypeAI")

add_executable(prototypeAI "main.cpp" "main.h")

target_include_directories(prototypeAI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(
	prototypeAI PUBLIC

	main.cpp
	main.h

	src/networkMain/iteratorVector/iteratorVector.h
	src/networkMain/iteratorVector/iteratorVector.cpp

	src/networkMain/layer/layer.cpp
	src/networkMain/layer/layer.h

	src/networkMain/node/node.cpp
	src/networkMain/node/node.h

	src/networkMain/networkMain.cpp
	src/networkMain/networkMain.h

)