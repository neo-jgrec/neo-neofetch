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
        return NULL;
    while (getline(&line, &len, fp) != -1) {
        if (strstr(line, "model name")) {
            cpu = malloc(sizeof(char) * (strlen(line) - 12));
            if (!cpu)
                return NULL;
            strcpy(cpu, line + 13);
            cpu[strlen(cpu) - 1] = '\0';
            break;
        }
    }
    fclose(fp);
    if (line)
        free(line);
    return cpu;
}
