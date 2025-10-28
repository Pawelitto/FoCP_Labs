cmake_minimum_required(VERSION 4.0)
project(FoCP_Labs)

set(CMAKE_CXX_STANDARD 20)

file(GLOB FoCP_Labs "lab*.cpp")

foreach(src ${FoCP_Labs})
    get_filename_component(name ${src} NAME_WE)
    add_executable(${name} ${src})
endforeach()

add_executable(main main.cpp)