/*
** neo-neofetch
** File description:
** cpu
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *fetch_cpu(void)
{
    FILE *fp = fopen("/proc/cpuinfo", "r");
    char *cpu = NULL;
    char *line = NULL;
    size_t len = 0;

    if (!fp)
        exit(84);
    while (!cpu && getline(&line, &len, fp) != -1) {
        if (!strstr(line, "model name"))
            continue;
        cpu = malloc(sizeof(char) * (strlen(line) - 12));
        if (!cpu)
            exit(84);
        strcpy(cpu, line + 13);
        cpu[strlen(cpu) - 1] = '\0';
    }
    if (fclose(fp) == EOF || !cpu || !line)
        exit(84);
    free(line);
    return cpu;
}
