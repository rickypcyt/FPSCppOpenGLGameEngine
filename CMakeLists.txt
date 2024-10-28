cmake_minimum_required(VERSION 3.10)
project(My3DGame)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLUT REQUIRED) # Add this line to find FreeGLUT
find_package(GLU REQUIRED)   # Add this line to find GLU

include_directories(include)

# Add the source files for your project
add_executable(My3DGame 
    src/main.cpp 
    src/movement.cpp 
    src/renderer.cpp 
    src/globals.cpp 
    src/cursor.cpp
    src/camera.cpp
    src/glad.c
)

# Link against OpenGL, GLEW, GLFW, FreeGLUT, and GLU
target_link_libraries(My3DGame 
    ${OPENGL_LIBRARIES} 
    GLEW::GLEW 
    glfw 
    GLUT::GLUT  # Link to FreeGLUT
    ${GLU_LIBRARIES}  # Link to GLU
)
