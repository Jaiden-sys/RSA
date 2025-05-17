cmake_minimum_required(VERSION 3.31)
project(RSA_Crypto)

set(CMAKE_CXX_STANDARD 20)

add_executable(RSA_Crypto main.cpp rsa/rsa.h
        rsa/rsa.cpp
        rsa/math.h
        rsa/math.cpp)
