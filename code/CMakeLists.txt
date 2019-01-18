cmake_minimum_required(VERSION 3.10)
project(code)

set(CMAKE_CXX_STANDARD 14)
find_program(
        CLANG_TIDY_EXE
        NAMES "clang-tidy-5.0"
        DOC "Path to clang-tidy executable"
)
if(NOT CLANG_TIDY_EXE)
    message(STATUS "clang-tidy not found.")
else()
    message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
    set(DO_CLANG_TIDY "${CLANG_TIDY_EXE}" "-checks=*,-clang-analyzer-alpha.*")
endif()



add_executable(code main.cpp DGraph.cpp DGraph.h)
add_executable(topSort topSort.cpp)

#set_target_properties(
#         PROPERTIES
#        CXX_STANDARD 14
#        CXX_STANDARD_REQUIRED ON
#        COMPILE_FLAGS "${WARNING_FLAGS}"
#)
#
#if(CLANG_TIDY_EXE)
#    set_target_properties(
#            topSort PROPERTIES
#            CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
#    )
#endif()

add_executable(dfs DFS.cpp)
add_executable(bfs BFS.cpp)
add_executable(topoSort610 topoSort610.cpp)
add_executable(transitive transitive.cpp)