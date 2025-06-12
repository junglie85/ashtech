cmake_minimum_required(VERSION 3.30)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(ashtech VERSION 0.0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

add_subdirectory(core)
add_subdirectory(plugins/window)

add_executable(ashtech
    "src/main.c"
)

target_compile_definitions(ashtech PRIVATE AT_INTERNAL_FN)

target_compile_features(ashtech PRIVATE c_std_11)
target_compile_options(ashtech PUBLIC /FC /Zi /W4 /WX /external:anglebrackets /external:W0)

target_link_libraries(ashtech
    PRIVATE
    at_core
    $<COMPILE_ONLY:at_window>
    Kernel32
)
