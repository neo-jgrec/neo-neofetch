/*
** neo-neofetch
** File description:
** shell.c
*/

#include <stdlib.h>
#include <libgen.h>
#include <string.h>

#include "neofetch.h"

char *fetch_shell(context_t *ctx)
{
    char *env_shell = getenv("SHELL");
    char *shell;

    if (!env_shell)
        exit(84);
    shell = malloc(sizeof(char) * (strlen(env_shell) + 1));
    if (!shell)
        exit(84);
    strcpy(shell, (ctx->shell_fullpath) ? env_shell : basename(env_shell));
    return shell;
}
