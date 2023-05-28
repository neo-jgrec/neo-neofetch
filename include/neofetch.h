/*
** neo-neofetch
** File description:
** header
*/

#ifndef NEOFETCH_H_
    #define NEOFETCH_H_

    #include <stdint.h>

    #include "fetch.h"
    #include "parse.h"
    #include "struct.h"

    #define HIDDEN_FILE "$HOME/.neo_neofetch_tmp"
    #define CONFIG_FILE "$HOME/.config/neo_neofetch/config"

    #define IS_SKIP(x)  (x == ' ' || x == '\t')

    #define WIDTH       20
    #define HEIGHT      10

void run_config(uint32_t);
bool is_image_supported(void);

#endif /* !NEOFETCH_H_ */
