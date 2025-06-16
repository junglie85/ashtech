cmake_minimum_required(VERSION 3.30)
project(sandbox VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sandbox
    "src/sandbox_main.cxx"
)

target_include_directories(sandbox
    PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
)

target_compile_features(sandbox PRIVATE cxx_std_11)
target_compile_options(sandbox PUBLIC /FC /Zi /W4 /WX /external:anglebrackets /external:W0)

target_link_libraries(sandbox
    PRIVATE
    ashtech
)
