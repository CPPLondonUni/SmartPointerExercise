cmake_minimum_required(VERSION 3.7)
project(SmartPointerExercise VERSION 1.0.0)

include_directories(include/ include/interface)

set(LIB_HEADERS include/exercise1.h include/exercise2.h include/interface/ILogger.h)

add_subdirectory(simple_smart_pointer)

add_executable(SmartPointerExercise1 src/test1.cpp)
add_executable(SmartPointerExercise2 src/test2.cpp)

set_target_properties(SmartPointerExercise1 SmartPointerExercise2 PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED YES
	FOLDER Exercise)

