cmake_minimum_required(VERSION 3.30)
project(ashtech_window VERSION 0.0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(HEADERS
    "include/at_window/window.h"
)

add_library(at_window
    SHARED
    "src/window.c"
    "${HEADERS}"
)

target_include_directories(at_window
    PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

target_compile_features(at_window PRIVATE c_std_11)
target_compile_options(at_window PUBLIC /FC /Zi /W4 /WX /external:anglebrackets /external:W0)

target_link_libraries(at_window
    PRIVATE
    at_core
)
