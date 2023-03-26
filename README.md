## neo-neofetch

A simple script to display system information in a neofetch-like format.
Written in C and bash.

### Compilation

#### If you are a lazy person

Use the `compile.sh` script. It will compile the program.

#### If you are not a lazy person

Before even try to compile, run `mkdir build`.

To compile, run `cmake -S . -B build` and then `cmake --build build`.

Now you can run `./build/neo-neofetch` to see the output.
