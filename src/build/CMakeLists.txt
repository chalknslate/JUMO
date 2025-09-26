cmake_minimum_required(VERSION 3.10)

project(engine VERSION 1.0)
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Source files
set(SRC_FILES
    ../main.c
    ../libs/glad/src/glad.c
    ../libs/stb_image/stb_image.c
)

# Enable AddressSanitizer
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -fno-omit-frame-pointer -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

# Ensure debug symbols are included
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

# Include directories
include_directories(
    ../files/
    ../files/classes/
    ../libs/glad/include/glad/
    ../libs/glad/include/KHR/
    ../libs/stb_image/
)

# Find OpenGL and GLFW
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# Create the executable
add_executable(engine ${SRC_FILES})

# Link libraries
target_link_libraries(engine OpenGL::GL glfw)
