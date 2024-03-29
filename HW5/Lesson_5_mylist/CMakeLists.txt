cmake_minimum_required(VERSION 3.28)

project(
    lesson_5
    VERSION 0.0.1
    DESCRIPTION "Lesson_5"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)

add_executable(lesson_5)
#add_library(lesson_5)
#add_library(MyList SHARED)

set(sources
    src/MyList.h
    src/Car.h
    src/main.cpp
    src/Car.cpp
)
target_sources(lesson_5 PRIVATE ${sources})

target_include_directories(lesson_5
    PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)
