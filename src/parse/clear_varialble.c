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
    FILE *file = fopen(get_hidden_file_name(), "w");

    if (!file || fclose(file) == EOF)
        exit(84);
}
