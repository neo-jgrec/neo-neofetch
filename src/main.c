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

    if (!cpu)
        return 84;
    printf("CPU: %s", cpu);
    if (!shell)
        return 84;
    printf("Shell: %s", shell);
    free(cpu);
    free(shell);
    return 0;
}
