cmake_minimum_required(VERSION 3.30)
project(ashtech_window VERSION 0.0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(HEADERS
    "include/ashtech_window.h"
)

add_library(ashtech_window
    SHARED
    "src/ashtech_window.c"
    "${HEADERS}"
)

target_include_directories(ashtech_window
    PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

target_compile_features(ashtech_window PRIVATE c_std_11)
target_compile_options(ashtech_window PUBLIC /FC /Zi /W4 /WX /external:anglebrackets /external:W0)

target_link_libraries(ashtech_window
    PRIVATE
    ashtech
)
