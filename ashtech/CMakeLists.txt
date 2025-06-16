cmake_minimum_required(VERSION 3.30)
project(ashtech VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "Pointer size: ${CMAKE_SIZEOF_VOID_P}")

find_package(SDL3 REQUIRED CONFIG PATHS "${CMAKE_SOURCE_DIR}/vendor/installed/cmake")

set(HEADERS
    "include/ashtech.hxx"
    "include/ashtech_app.hxx"
)

add_library(ashtech
    "src/ashtech_app.cxx"
    ${HEADERS}
)

target_include_directories(ashtech
    PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
)

target_compile_features(ashtech PRIVATE cxx_std_11)
target_compile_options(ashtech PUBLIC /FC /Zi /W4 /WX /external:anglebrackets /external:W0)

set(LIBS "")
list(APPEND LIBS SDL3::SDL3-static)

target_link_libraries(ashtech PRIVATE ${LIBS})
