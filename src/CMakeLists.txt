cmake_minimum_required(VERSION 3.27)
project(aoc2023)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall \
                                        -Wextra \
                                        -Werror \
                                        -pedantic \
                                        -pedantic-errors \
                                        -fsanitize=undefined"
)

set(DAY01 "day01/")
set(SOURCES
    main.cpp
    ${DAY01}/day01.cpp
)

add_executable("${PROJECT_NAME}" ${SOURCES})

target_include_directories("${PROJECT_NAME}"
                           PRIVATE
                           "${DAY01}"
)
