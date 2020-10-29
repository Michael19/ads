cmake_minimum_required(VERSION 2.8)

project(homework)
set(SOURCES
    pqueue.h
    main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

add_executable(R main.cpp)
