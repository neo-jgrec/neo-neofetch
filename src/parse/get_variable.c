/*
** neo-neofetch
** File description:
** get_variable.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "neofetch.h"

char *get_variable(const char *variable)
{
    char *hidden_file = get_hidden_file_name();
    FILE *fp = fopen(hidden_file, "r");
    char *resolution = malloc(sizeof(char) * 20);
    char *line = NULL;
    size_t len = 0;
    struct stat st;

    if (!resolution || !fp || stat(hidden_file, &st) == -1)
        exit(84);
    while (getline(&line, &len, fp) != -1) {
        if (!strstr(line, variable))
            continue;
        strcpy(resolution, line + strlen(variable) + 2);
        resolution[strlen(resolution) - 1] = '\0';
        if (fclose(fp) == EOF)
            exit(84);
        return resolution;
    }
    exit(84);
}
