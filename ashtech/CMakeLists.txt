cmake_minimum_required(VERSION 3.30)
project(ashtech VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL3 REQUIRED CONFIG PATHS "${CMAKE_SOURCE_DIR}/build/vendor/install/cmake")

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

target_compile_features(ashtech PRIVATE cxx_std_23)
target_compile_options(ashtech PUBLIC /FC /Zi /W4 /WX /external:anglebrackets /external:W0)

set(LIBS "")
list(APPEND LIBS SDL3::SDL3-static)

target_link_libraries(ashtech PRIVATE ${LIBS})

if (MSVC AND NOT BUILD_SHARED_LIBS)
    # Set the output name for debugger files, otherwise they are not generated:
    set_target_properties(ashtech
            PROPERTIES
            COMPILE_PDB_NAME_DEBUG ashtech
            COMPILE_PDB_NAME_RELEASE ashtech
            COMPILE_PDB_NAME_MINSIZEREL ashtech
            COMPILE_PDB_NAME_RELWITHDEBINFO ashtech)
endif ()
