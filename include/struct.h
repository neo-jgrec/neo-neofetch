/*
** neo-neofetch
** File description:
** struct.h
*/

#ifndef STRUCT_H_
	#define STRUCT_H_

    #include <sys/queue.h>

typedef enum {
    NONE,
    ASCII,
    KITTY,
    W3M,
    ITERM2,
    CACA,
    TIMG,
    CATIMG
} image_type_t;

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} rgb_t;

typedef struct {
    char *name;
    char *font_size;
    rgb_t *foreground_color;
    rgb_t *background_color;
} text_t;

typedef struct {
    int top;
    int bottom;
    int left;
    int right;
} padding_t;

typedef struct {
    text_t *name;
    text_t *value;
    text_t *separator;
    padding_t *padding;
} info_t;

typedef struct element_s {
    info_t *info;
    TAILQ_ENTRY(element_s) next;
} element_t;

typedef struct category_s {
    text_t *name;
    TAILQ_HEAD(, element_s) elements;
    TAILQ_ENTRY(category_s) next;
} category_t;

typedef struct {
    text_t *title;
    TAILQ_HEAD(, category_s) categories;
    image_type_t image_type;
    char *image_path;
    int image_size;
} main_t;

#endif /* !STRUCT_H_ */
