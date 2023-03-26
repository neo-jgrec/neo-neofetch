#!/bin/bash
##
## neo-neofetch
## File description:
## compile
##

if [ $# == 0 ]; then
    mkdir -p build
    cmake -S . -B build
    cmake --build build
    mv build/neo-neofetch .
    env echo -e "\e[1;32m[+] \e[0mCompiled successfully, binary is in the root directory."
else
    if [ $1 == "debug" ]; then
        mkdir -p build
        cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
        cmake --build build
        mv build/neo-neofetch .
        env echo -e "\e[1;32m[+] \e[0mCompiled successfully, binary is in the root directory."
        exit 0
    fi
    env echo -e "\e[1;31m[-] \e[0mInvalid argument."
fi
