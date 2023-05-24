/*
** neo-neofetch
** File description:
** get_hidden_file.c
*/

#include <stdlib.h>
#include <string.h>

#include "neofetch.h"

char *get_hidden_file_name(void)
{
    char *home = getenv("HOME");
    char *hidden_file = malloc(sizeof(char) * 100);

    if (!hidden_file || !home)
        exit(84);
    strcpy(hidden_file, home);
    strcat(hidden_file, HIDDEN_FILE + strlen("$HOME"));
    return hidden_file;
}
