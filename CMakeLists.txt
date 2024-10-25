cmake_minimum_required(VERSION 3.10)
project(My3DGame)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(include)

add_executable(My3DGame src/main.cpp src/movement.cpp src/renderer.cpp)

target_link_libraries(My3DGame ${OPENGL_LIBRARIES} GLEW::GLEW glfw)
