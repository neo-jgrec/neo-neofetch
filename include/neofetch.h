/*
** neo-neofetch
** File description:
** header
*/

#ifndef NEOFETCH_H_
    #define NEOFETCH_H_

    #include "fetch.h"
    #include "parse.h"
    #include "struct.h"

    #define HIDDEN_FILE "$HOME/.neo_neofetch_tmp"
    #define CONFIG_FILE "$HOME/.config/neo_neofetch/config"

    #define IS_SKIP(x) (x == ' ' || x == '\t')

#endif /* !NEOFETCH_H_ */
