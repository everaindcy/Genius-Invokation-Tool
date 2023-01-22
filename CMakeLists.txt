project(GENIUS-INVOKATION-TOOL)

cmake_minimum_required(VERSION 3.24)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src/)
set(LUA_DIR ${PROJECT_SOURCE_DIR}/lualib/)
set(TABLE_DIR ${SRC_DIR}/GITCGcore/table/)

include_directories(
    ${LUA_DIR}/include/
    ${TABLE_DIR}
)

link_directories(
    ${LUA_DIR}/lib/
)

aux_source_directory(${SRC_DIR}/test/ SRC_LIST)

add_executable(test ${SRC_LIST})

target_link_libraries(test liblua.a)