cmake_minimum_required(VERSION 3.10.2)
project(SimpleGl)

message("CMAKE_ROOT: ${CMAKE_ROOT}")
message("CMAKE_MODULE_PATH : ${CMAKE_MODULE_PATH}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

# set(OpenGL_GL_PREFERENCE GLVND)
# find_package(OpenGL REQUIRED)
# find_package(GLUT REQUIRED)
# message("GL Libraries : ${OPENGL_LIBRARIES}")
# message("GL Location : ${OPENGL_INCLUDE_DIR}")
# message("GLUT Libraries : ${GLUT_LIBRARY}")

find_package(SDL2 REQUIRED)
find_library(SDL2_IMAGE_LIBRARY NAMES SDL2_image PATHS /usr/lib/x86_64-linux-gnu)
find_path(SDL2_IMAGE_INCLUDE_DIR SDL_image.h PATHS /usr/include/SDL2)
message("SDL2 Image Libraries : ${SDL2_IMAGE_LIBRARY}")


set(SOURCES main.cpp 
    Buffer.cpp Camera.cpp glad.c Input.cpp Quad.cpp Cube.cpp Screen.cpp Shader.cpp Texture.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${SDL2_IMAGE_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARY} dl)

#target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})