# https://github.com/SFML/cmake-sfml-project
cmake_minimum_required(VERSION 3.22...4.0.1)
project(SpaceInvaders LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 20)

# write result to bin folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_FLAGS "-g -Wall -pedantic")

# get SFML
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

# get GTest
FetchContent_Declare(GTest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(GTest)

# add the contents of the src and test folders
add_subdirectory(src)
add_subdirectory(test)

target_compile_features(SpaceInvaders PRIVATE cxx_std_20)
target_compile_features(Test PRIVATE cxx_std_20)

# link SFML
target_link_libraries(SpaceInvaders PRIVATE SFML::Graphics)
target_link_libraries(Test gtest gtest_main gmock pthread SFML::Graphics)

# add assets (fonts and images) to bin folder
add_custom_target(copy_assets
COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/bin/assets
)
add_dependencies(SpaceInvaders copy_assets)