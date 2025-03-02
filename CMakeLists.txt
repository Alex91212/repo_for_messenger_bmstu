cmake_minimum_required(VERSION 3.30)
project(messenger_bmstu C)

set(CMAKE_C_STANDARD 17)

add_executable(messenger_bmstu main.c
        server.c
        cmake-build-debug/client.c)
