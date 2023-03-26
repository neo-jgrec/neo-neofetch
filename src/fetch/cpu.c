/*
** neo-neofetch
** File description:
** cpu
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

char *fetch_cpu(void)
{
    char *cpu = malloc(sizeof(char) * 100);
    FILE *fp = fopen("/proc/cpuinfo", "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (fp == NULL)
        return NULL;
    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, "model name") != NULL) {
            strcpy(cpu, line);
            break;
        }
    }
    fclose(fp);
    if (line)
        free(line);
    return cpu;
}
