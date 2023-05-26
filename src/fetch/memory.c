/*
** EPITECH PROJECT, 2022
** neo-neofetch
** File description:
** memory.c
*/

#define _GNU_SOURCE
#include <stdio.h>

#include <stdlib.h>
#include <stdint.h>

#include "neofetch.h"

char *fetch_memory(bool percent)
{
    char *memtotal = get_variable("/proc/meminfo", "MemTotal");
    char *memavailable = get_variable("/proc/meminfo", "MemAvailable");
    uint32_t memtotal_int = atoi(memtotal);
    uint32_t memavailable_int = atoi(memavailable);
    uint32_t memused_int = memtotal_int - memavailable_int;
    char memory_percent[10] = {0};
    char *memory;

    if (!memtotal || !memavailable)
        exit(84);
    if (percent)
        sprintf(memory_percent, " (%d%%)", memused_int * 100 / memtotal_int);
    if (asprintf(&memory, "%dMiB / %dMiB%s",
        memused_int / 1024, memtotal_int / 1024, memory_percent) == -1)
        exit(84);
    free(memtotal);
    free(memavailable);
    return memory;
}
