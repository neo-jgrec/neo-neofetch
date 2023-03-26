/*
** neo-neofetch
** File description:
** shell.c
*/

#include <stdlib.h>
#include <libgen.h>
#include <string.h>
#include <stdbool.h>

char *fetch_shell(bool full_path)
{
    char *env_shell = getenv("SHELL");
    char *shell;

    if (!env_shell)
        return NULL;
    shell = malloc(sizeof(char) * (strlen(env_shell) + 1));
    if (!shell)
        return NULL;
    if (full_path)
        strcpy(shell, env_shell);
    else
        strcpy(shell, basename(env_shell));
    return shell;
}
