/*
** EPITECH PROJECT, 2023
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
    char *term_name = NULL;

    if (!term)
        return NULL;
    term_name = malloc(sizeof(char) * (strlen(term) + 1));
    if (!term_name)
        return NULL;
    if (prefix)
        strcpy(term_name, term);
    else
        strcpy(term_name, term + 6);
    return term_name;
}
