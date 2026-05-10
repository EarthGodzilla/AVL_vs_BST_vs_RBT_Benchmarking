cmake_minimum_required(VERSION 3.16)
project(BenchmarkTrees)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(benchmark
    main.cpp
    src/bst.cpp
    src/avl.cpp
    src/rbt.cpp
)