/*
** neo-neofetch
** File description:
** uptime.c
*/

#include <malloc.h>
#include <string.h>
#include <stdint.h>

static void display_format(char *uptime, uint64_t seconds)
{
    char *format;

    if (seconds >= 3600) {
        format = (seconds / 3600 == 1) ? "%d hour " : "%d hours ";
        sprintf(uptime, format, seconds / 3600);
    }
    if (seconds >= 60) {
        format = (seconds / 60 % 60 == 1) ? "%d minute " : "%d minutes ";
        sprintf(uptime + strlen(uptime), format, seconds / 60 % 60);
    }
    format = (seconds % 60 == 1) ? "%d second " : "%d seconds ";
    sprintf(uptime + strlen(uptime), format, seconds % 60);
}

char *fetch_uptime(void)
{
    FILE *file = fopen("/proc/uptime", "r");
    char buffer[BUFSIZ];
    uint64_t seconds;
    char *uptime = malloc(sizeof(char) * 256);

    if (!fgets(buffer, BUFSIZ, file))
        return NULL;
    sscanf(buffer, "%zu", &seconds);
    display_format(uptime, seconds);
    if (!uptime)
        return NULL;
    uptime[strlen(uptime) - 1] = '\0';
    return (fclose(file) == EOF) ? NULL : uptime;
}
