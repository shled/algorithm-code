cmake_minimum_required(VERSION 3.8)

project(algorithm-code)
add_compile_options(-std=c++11)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(LEETCODE_PROBLEMS
    # No.0034 Find First and Last Position of Element in Sorted Array
    find_first_and_last_position_of_element_in_sorted_array
    # No.0046 Permutations
    permutations
    # No.0051 N-Queens
    n_queens
    # No.0111 Minimum Depth of Binary Tree
    minimum_depth_of_binary_tree
    # No.0141 Linked List Cycle
    linked_list_cycle
    # No.0142 Linked List Cycle II
    linked_list_cycle_ii
    # No.0215 Kth Largest Element in an Array
    kth_largest_element_in_an_array
    # No.0509 Fibonacci Number
    fibonacci_number
    # No.0322 Coin Change
    coin_change
    # No.0347 Top K Frequent Elements
    top_k_frequent_elements
    # No.0704 Binary Search
    binary_search
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
