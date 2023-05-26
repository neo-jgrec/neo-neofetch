/*
** neo-neofetch
** File description:
** parse.h
*/

#ifndef PARSE_H_
    #define PARSE_H_

char *get_filepath(char *file);

void clear_variable(void);

char *get_variable(const char *filepath, const char *variable);

#endif /* !PARSE_H_ */
