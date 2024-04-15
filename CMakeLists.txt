cmake_minimum_required(VERSION 3.29)

project(rpg_game)

add_compile_options(-fdiagnostics-color=always -Wall -std=c++23 -g)

find_package(SFML REQUIRED audio)

include_directories(inc)

aux_source_directory(src SRC_LIST)

add_executable(rpg_game ${SRC_LIST})
target_link_libraries(rpg_game sfml-audio)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)