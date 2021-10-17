cmake_minimum_required(VERSION 3.13)
project(A_Tuples_library C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES1 TupleFunctionsa.c TupleFunctionsb.c Functionsa.h Functionsb.h)
add_library(list SHARED ${SOURCE_FILES1})
set(SOURCE_FILES2 main.c sgets.c sgets.h maina.c mainb.c)
add_executable(app1 ${SOURCE_FILES2})
target_link_libraries(app1 list)
