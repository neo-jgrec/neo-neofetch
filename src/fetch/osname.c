/*
** neo-neofetch
** File description:
** osname.c
*/

#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>

char *fetch_osname(void)
{
    struct utsname utsname;
    char *osname = calloc(256, sizeof(char));

    if (!osname || uname(&utsname) == -1)
        exit(84);
    strcpy(osname, utsname.sysname);
    return osname;
}
