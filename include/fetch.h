/*
** EPITECH PROJECT, 2023
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

#endif /* !FETCH_H_ */
