project(snt2)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -pedantic -Wextra -ggdb")

add_executable(${PROJECT_NAME}
   stringbin.cpp
   combinationgenerator.cpp
   partitiongenerator.cpp
   main.cpp
)

