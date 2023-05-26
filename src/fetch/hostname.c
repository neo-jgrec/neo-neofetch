/*
** neo-neofetch
** File description:
** hostname.c
*/

#include <unistd.h>
#include <stdlib.h>

#include "neofetch.h"

char *fetch_hostname(UNUSED context_t *ctx)
{
    char *hostname = malloc(sizeof(char) * 256);

    if (!hostname || gethostname(hostname, 256) == -1)
        exit(84);
    return hostname;
}
