/*
** neo-neofetch
** File description:
** run_config.c
*/

#include <string.h>
#include <stdlib.h>
#include <curses.h>

#include "neofetch.h"

static fetch_t *get_fetch(void)
{
    fetch_t *fetch = malloc(sizeof(static_fetch));

    if (!fetch)
        exit(84);
    memcpy(fetch, static_fetch, sizeof(static_fetch));
    return fetch;
}

static option_t *get_options(context_t *ctx)
{
    option_t static_options[] = {
        {"shell_fullpath", &ctx->shell_fullpath},
        {"terminal_prefix", &ctx->terminal_prefix},
        {"memory_percent", &ctx->memory_percent},
        {NULL, NULL}
    };
    option_t *options = malloc(sizeof(static_options));

    if (!options)
        exit(84);
    memcpy(options, static_options, sizeof(static_options));
    return options;
}

static void clean_variable(char *variable)
{
    uint32_t i = 0;

    for (; variable[i] && !IS_SKIP(variable[i]) && variable[i] != '\n'; i++);
    variable[i] = '\0';
}

static void set_value(context_t *ctx, fetch_t *fetch, option_t *options,
    uint32_t offset)
{
    char *variable;
    char *value;
    uint32_t i;

    clear_variable();
    for (i = 0; options[i].name; i++) {
        value = get_variable(CONFIG_FILE, options[i].name);
        clean_variable(value);
        *options[i].value = !strcmp(value, "true");
        free(value);
    }
    free(options);
    for (i = 0; fetch[i].name; i++) {
        value = get_variable(CONFIG_FILE, fetch[i].name);
        clean_variable(value);
        fetch[i].enabled = strcmp(value, "false");
        free(value);
        if (!fetch[i].enabled)
            continue;
        variable = fetch[i].fetch(ctx);
        printf("%*s%-9s%s   %s\n", offset, "", fetch[i].name, ":", variable);
        free(variable);
    }
    if (offset > 1)
        for (uint32_t j = 0; j <= HEIGHT - i; j++)
            printf("\n");
}

void run_config(uint32_t offset)
{
    context_t *ctx = calloc(1, sizeof(context_t));
    fetch_t *fetch;
    option_t *options;

    if (!ctx)
        exit(84);
    fetch = get_fetch();
    options = get_options(ctx);
    set_value(ctx, fetch, options, offset);
    free(fetch);
    free(ctx);
}
