cmake_minimum_required(VERSION 3.10) # Ensure a modern CMake version
project(Mosaic)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include directories from OpenCV
include_directories(${OpenCV_INCLUDE_DIRS})

# Get all cpp files
file(GLOB Mosaic_SRC "*.cpp")

# Create an executable
add_executable(Mosaic ${Mosaic_SRC})

# Link OpenCV libraries
target_link_libraries(Mosaic ${OpenCV_LIBS})
