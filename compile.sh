##
## neo-neofetch
## File description:
## compile
##

mkdir -p build
cmake -S . -B build
cmake --build build
mv build/neo-neofetch .
env echo -e "\e[1;32m[+] \e[0mCompiled successfully, binary is in the root directory."
