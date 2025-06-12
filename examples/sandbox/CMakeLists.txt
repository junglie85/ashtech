cmake_minimum_required(VERSION 3.30)
project(ashtech_example_sandbox VERSION 0.0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(ashtech_example_sandbox
    "src/ashtech_registry.c"
)

target_include_directories(ashtech_example_sandbox
    PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
)

target_compile_features(ashtech_example_sandbox PRIVATE c_std_11)
target_compile_options(ashtech_example_sandbox PUBLIC /FC /Zi /W4 /WX /external:anglebrackets /external:W0)

target_link_libraries(ashtech_example_sandbox
    PRIVATE
    at_core
    $<COMPILE_ONLY:at_window>
)
