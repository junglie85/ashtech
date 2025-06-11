cmake_minimum_required(VERSION 3.30)
project(ashtech VERSION 0.0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(HEADERS
    "include/ashtech.h"
    "include/ashtech_api_registry.h"
    "include/ashtech_thing.h"
)

add_library(ashtech
    "src/ashtech_api_registry.c"
    "src/ashtech_thing.c"
    ${HEADERS}
)

target_include_directories(ashtech
    PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
)

target_compile_features(ashtech PRIVATE c_std_11)
target_compile_options(ashtech PUBLIC /FC /Zi /W4 /WX /external:anglebrackets /external:W0)
