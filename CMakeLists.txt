cmake_minimum_required(VERSION 3.10)

project(Ivory)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(Ivory src/main.cpp)

target_link_libraries(Ivory OpenGL::GL glfw)
