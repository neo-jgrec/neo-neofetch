/*
** neo-neofetch
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "neofetch.h"

int main()
{
    char *image = get_variable_string(CONFIG_FILE, "image");
    char command[BUFSIZ];
    bool as_image = strcmp(image, "null") && is_image_supported();
    uint32_t offset = 0;
    pid_t pid = 1;

    if (as_image) {
        pid = fork();
        offset = WIDTH;
    }
    if (pid == -1 || system("clear") == -1)
        exit(84);
    if (pid == 0) {
        sprintf(command,
            "kitty +kitten icat --place %ix%i@0x0 %s 2> /dev/null",
            offset, HEIGHT, image);
        if (system(command) == -1)
            exit(84);
        exit(0);
    }
    waitpid(pid, NULL, 0);
    free(image);
    run_config(offset + 1);
    return 0;
}
