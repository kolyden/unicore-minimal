cmake_minimum_required(VERSION 3.8.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_EXTENSIONS OFF)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1)

# OPTIONS ######################################################################

# PROJECT ######################################################################
project(Minimal)

set(LIBS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs")
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
add_subdirectory("${LIBS_DIR}/unicore")

# CORE #########################################################################
file(GLOB_RECURSE CORE_SOURCE "${SRC_DIR}/*.cpp" "${SRC_DIR}/*.hpp")

add_executable(core "${CORE_SOURCE}")
unicore_init_executable(core)
target_link_libraries(core PRIVATE unicore)
unicore_init_assets(core "${CMAKE_CURRENT_SOURCE_DIR}/assets")

unciore_link_stb(core)
unciore_link_xml(core)
unciore_link_fnt(core)
unciore_link_imgui(core)
unciore_link_wasm(core)