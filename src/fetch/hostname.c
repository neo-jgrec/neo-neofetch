/*
** EPITECH PROJECT, 2023
** neo-neofetch
** File description:
** hostname.c
*/

#include <unistd.h>
#include <malloc.h>

char *fetch_hostname(void)
{
    char *hostname = malloc(sizeof(char) * 256);

    if (!hostname)
        return NULL;
    if (gethostname(hostname, 256) == -1)
        return NULL;
    return hostname;
}