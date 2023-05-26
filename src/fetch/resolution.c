/*
** neo-neofetch
** File description:
** resolution.c
*/

#include <string.h>
#include <stdlib.h>

#include "neofetch.h"

char *fetch_resolution(UNUSED context_t *ctx)
{
    char *cmd = calloc(100, sizeof(char));

    if (!cmd)
        exit(84);
    strcpy(cmd, "echo resolution: ");
    strcat(cmd, "$(xrandr | grep \"*\" | cut -d\" \" -f4) >> ");
    strcat(cmd, HIDDEN_FILE);
    if (system(cmd) == -1)
        exit(84);
    free(cmd);
    return get_variable(HIDDEN_FILE, "resolution");
}
