/*
** neo-neofetch
** File description:
** is_image_supported.c
*/

#include <stdlib.h>
#include <string.h>

#include "neofetch.h"

bool is_image_supported(void)
{
    char *term = getenv("TERM");;

    if (!term)
        exit(84);
    return !strcmp(term + 6, "kitty");
}
