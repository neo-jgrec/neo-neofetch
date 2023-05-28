/*
** neo-neofetch
** File description:
** term.c
*/

#include <stdlib.h>
#include <string.h>

#include "neofetch.h"

char *fetch_terminal(context_t *ctx)
{
    char *term = getenv("TERM");
    char *term_name;

    if (!term)
        exit(84);
    term_name = malloc(sizeof(char) * (strlen(term) + 1));
    if (!term_name)
        exit(84);
    strcpy(term_name, (ctx->terminal_prefix) ? term : term + 6);
    return term_name;
}
