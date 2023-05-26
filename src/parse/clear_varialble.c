/*
** neo-neofetch
** File description:
** clear_varialble.c
*/

#include <stdio.h>
#include <stdlib.h>

#include "neofetch.h"

void clear_variable(void)
{
    char *hidden_file = get_filepath(HIDDEN_FILE);
    FILE *file = fopen(hidden_file, "w");

    free(hidden_file);
    if (!file || fclose(file) == EOF)
        exit(84);
}
