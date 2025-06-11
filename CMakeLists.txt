cmake_minimum_required(VERSION 3.30)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(ashtech_engine VERSION 0.0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

add_subdirectory(ashtech)
add_subdirectory(plugins/ashtech_window)

add_executable(ashtech_main
    "src/main.c"
)

target_compile_definitions(ashtech_main PRIVATE AT_INTERNAL_FN)

target_compile_features(ashtech_main PRIVATE c_std_11)
target_compile_options(ashtech_main PUBLIC /FC /Zi /W4 /WX /external:anglebrackets /external:W0)

target_link_libraries(ashtech_main
    PRIVATE
    ashtech
    $<COMPILE_ONLY:ashtech_window>
    Kernel32
)
