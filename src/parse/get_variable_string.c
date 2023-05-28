/*
** neo-neofetch
** File description:
** get_variable_string.c
*/

#include <string.h>
#include <stdlib.h>

#include "neofetch.h"

char *get_variable_string(const char *filepath, const char *variable)
{
    char *value = get_variable(filepath, variable);
    char *result = malloc(sizeof(char) * (strlen(value) * 2 + 1));
    uint32_t i = 0;
    uint32_t j = 0;

    if (!value) {
        free(value);
        exit(84);
    }
    strcpy(result, value);
    free(value);
    if (!strcmp(result, "null"))
        return result;
    for (; IS_SKIP(result[i]); i++);
    if (result[i] == '"')
        i++;
    else
        return result;
    for (; result[i] && result[i] != '"'; i++) {
        if (result[i] == ' ')
            result[j++] = '\\';
        result[j++] = result[i];
    }
    result[j] = '\0';
    return result;
}
