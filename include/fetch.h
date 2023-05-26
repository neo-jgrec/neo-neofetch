/*
** neo-neofetch
** File description:
** fetch.h
*/

#ifndef FETCH_H_
	#define FETCH_H_

    #include <stdbool.h>

    #define UNUSED __attribute__((unused))

typedef struct context_s {
    bool shell_fullpath;
    bool terminal_prefix;
    bool memory_percent;
} context_t;

char *fetch_cpu(context_t *ctx);
char *fetch_shell(context_t *ctx);
char *fetch_terminal(context_t *ctx);
char *fetch_hostname(context_t *ctx);
char *fetch_uptime(context_t *ctx);
char *fetch_osname(context_t *ctx);
char *fetch_resolution(context_t *ctx);
char *fetch_memory(context_t *ctx);

typedef struct fetch_s {
    char *name;
    char *(*fetch)(context_t *ctx);
    bool enabled;
} fetch_t;

static const fetch_t static_fetch[] = {
    {"hostname", fetch_hostname},
    {"cpu", fetch_cpu},
    {"uptime", fetch_uptime},
    {"shell", fetch_shell},
    {"terminal", fetch_terminal},
    {"osname", fetch_osname},
    {"resolution", fetch_resolution},
    {"memory", fetch_memory},
    {NULL, NULL}
};

#endif /* !FETCH_H_ */
