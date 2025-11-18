cmake_minimum_required(VERSION 3.10)
project(Lab_6)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Lab_6
        lab06.cpp
        find.cpp
        find_sorted.cpp
        words_counter.cpp
        words_map.cpp
        unique_words.cpp
        diff_words.cpp
        reverse_num.cpp
        pluses_deleter.cpp
        sort_list.cpp
)

