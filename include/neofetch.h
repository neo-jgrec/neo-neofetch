/*
** neo-neofetch
** File description:
** header
*/

#ifndef NEOFETCH_H_
    #define NEOFETCH_H_

    #include <stdio.h>
    #include <stdbool.h>

char *fetch_cpu(void);

char *fetch_shell(bool full_path);

#endif /* !NEOFETCH_H_ */
