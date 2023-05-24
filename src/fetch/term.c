/*
** neo-neofetch
** File description:
** term.c
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *fetch_term(bool prefix)
{
    char *term = getenv("TERM");
    char *term_name;

    if (!term)
        exit(84);
    term_name = malloc(sizeof(char) * (strlen(term) + 1));
    if (!term_name)
        exit(84);
    strcpy(term_name, (prefix) ? term : term + 6);
    return term_name;
}
