cmake_minimum_required(VERSION 3.19)
project(DataStructC C)

set(CMAKE_C_STANDARD 11)

add_executable(DataStructC main.c)


add_executable(DataStructC1 struct/SqList.c)

add_executable(input base/input.c)
add_executable(input1 base/input1.c)

add_executable(pointer base/pointer.c)


add_executable(kmp struct/kmp.c)