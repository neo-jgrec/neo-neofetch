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

static char *extract_variable(char *line, const char *searched_variable)
{
    u_int32_t skip = strlen(searched_variable) + 2;
    char *variable;

    for (; line[skip] && IS_SKIP(line[skip]); skip++);
    variable = malloc(sizeof(char) * (strlen(line + skip) + 1));
    if (!variable)
        exit(84);
    strcpy(variable, line + skip);
    variable[strlen(line + skip) - 1] = '\0';
    return variable;
}

static char *alloc_string(const char *ref_string)
{
    char *string = malloc(sizeof(char) * (strlen(ref_string) + 1));

    if (!string)
        exit(84);
    strcpy(string, ref_string);
    string[strlen(ref_string)] = '\0';
    return string;
}

char *get_variable(const char *filepath, const char *searched_variable)
{
    char *hidden_file = (filepath[0] == '$') ? get_filepath(filepath) :
        alloc_string(filepath);
    FILE *fp = fopen(hidden_file, "r");
    char *variable = NULL;
    char *line = NULL;
    size_t len = 0;
    struct stat st;

    if (!fp || stat(hidden_file, &st) == -1)
        exit(84);
    free(hidden_file);
    for (; getline(&line, &len, fp) != -1;) {
        line[strlen(line)] = '\0';
        if (strncmp(line, searched_variable, strlen(searched_variable)) ||
            line[strlen(searched_variable)] != ':')
            continue;
        variable = extract_variable(line, searched_variable);
        free(line);
        if (fclose(fp) == EOF)
            exit(84);
        return variable;
    }
    if (line)
        free(line);
    if (fclose(fp) == EOF)
        exit(84);
    return alloc_string("null");
}
