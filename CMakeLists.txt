cmake_minimum_required(VERSION 3.30)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(ashtech VERSION 0.0.1 LANGUAGES CXX)

# include(CMakePrintHelpers) # for troubleshooting (optional)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

add_subdirectory(ashtech)
add_subdirectory(sandbox)
