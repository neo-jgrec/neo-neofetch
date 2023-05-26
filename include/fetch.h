/*
** neo-neofetch
** File description:
** fetch.h
*/

#ifndef FETCH_H_
	#define FETCH_H_

    #include <stdbool.h>

char *fetch_cpu(void);

char *fetch_shell(bool full_path);

char *fetch_term(bool prefix);

char *fetch_hostname(void);

char *fetch_uptime(void);

char *fetch_osname(void);

char *fetch_resolution(void);

char *fetch_memory(bool percent);

#endif /* !FETCH_H_ */
