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

### Usage

`neo-neofetch` is a simple program. It takes no arguments and outputs the system information,
I can be used in a shell script to display the system information in a neofetch-like format.

If you want to parametrize `neo-neofetch` see for config inside the `$HOME/.config/neo_neofetch/config` file.

### Parameters for config file

Ich line of the config file is a parameter, the format is `<parameter>: <value>`.

The value are `true` or `false`, except for image.

When the default value is not set, it is `true`.

Image can only be displayed if your terminal supports it, (currently only kitty).

| Parameter         | Description                        | Default value |
|-------------------|------------------------------------|---------------|
| `hostname`        | Hostname to display                |               |
| `cpu`             | CPU to display                     |               |
| `uptime`          | Uptime to display                  |               |
| `shell`           | Shell to display                   |               |
| `shell_fullpath`  | Display the full path of the shell | `false`       |
| `terminal`        | Terminal to display                |               |
| `terminal_prefix` | Prefix to display before terminal  | `false`       |
| `osname`          | OS name to display                 |               |
| `resolution`      | Resolution to display              |               |
| `memory`          | Memory to display                  |               |
| `memory_percent`  | Display memory in percent          | `false`       |
| `image`           | Image to display                   | `"<path>"`    |
