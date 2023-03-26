/*
** neo-neofetch
** File description:
** main
*/

#include <malloc.h>

#include "neofetch.h"

int main(void)
{
    char *cpu = fetch_cpu();
    char *shell = fetch_shell(false);
    char *term = fetch_term(false);

    if (!cpu)
        return 84;
    printf("CPU: %s\n", cpu);
    if (!shell)
        return 84;
    printf("Shell: %s\n", shell);
    if (!term)
        return 84;
    printf("Terminal: %s\n", term);
    free(cpu);
    free(shell);
    return 0;
}
