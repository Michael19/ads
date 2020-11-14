cmake_minimum_required(VERSION 2.8)

project(homework)
set(SOURCES
    pqueue.h
    insertion_sort.h
    main.cpp)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lpthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")

add_executable(${PROJECT_NAME} ${SOURCES})

add_executable(R main.cpp)
#add_executable(R2 main2.cpp)
