cmake_minimum_required(VERSION 3.16)
project(OpenGL_3D_House C)

set(CMAKE_C_STANDARD 11)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(main src/main.c src/solid.c src/wire.c)

target_link_libraries(main ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})