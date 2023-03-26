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

    if (!cpu)
        return 84;
    printf("CPU: %s", cpu);
    free(cpu);
    return 0;
}
