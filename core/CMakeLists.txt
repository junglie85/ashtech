cmake_minimum_required(VERSION 3.30)
project(ashtech_core VERSION 0.0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(HEADERS
    "include/at/ashtech.h"
    "include/at/api_registry.h"
    "include/at/thing.h"
)

add_library(at_core
    "src/api_registry.c"
    "src/thing.c"
    ${HEADERS}
)

target_include_directories(at_core
    PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
)

target_compile_features(at_core PRIVATE c_std_11)
target_compile_options(at_core PUBLIC /FC /Zi /W4 /WX /external:anglebrackets /external:W0)
