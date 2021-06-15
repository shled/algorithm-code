cmake_minimum_required(VERSION 3.8)

project(algorithm-code)
add_compile_options(-std=c++11)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(LEETCODE_PROBLEMS
    # No.0046 Permutations
    permutations
    # No.0051 N-Queens
    n_queens
    # No.0111 Minimum Depth of Binary Tree
    minimum_depth_of_binary_tree
    # No.0509 Fibonacci Number
    fibonacci_number
    # No.0322 Coin Change
    coin_change
    # No.0752 Open the Lock
    open_the_lock
)

foreach(problem ${LEETCODE_PROBLEMS})
    MESSAGE(${problem})
    add_executable(${problem}
        ${PROJECT_SOURCE_DIR}/leetcode/${problem}/solution.cpp
        ${PROJECT_SOURCE_DIR}/leetcode/${problem}/unittest.cpp)
    target_link_libraries(${problem} gtest gtest_main)
endforeach(problem)
