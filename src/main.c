/*
** neo-neofetch
** File description:
** main
*/

#include <malloc.h>
#include <ncurses.h>
#include <string.h>

#include "neofetch.h"

int main()
{
    initscr();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(1));

    move(0, (COLS / 1.2) - strlen("CPU: ") - strlen(fetch_cpu()) / 2);
    printw("CPU: %s", fetch_cpu());

    move(1, (COLS / 1.2) - strlen("Shell: ") - strlen(fetch_shell(false)) / 2);
    printw("Shell: %s", fetch_shell(false));

    move(2, (COLS / 1.2) - strlen("Terminal: ") - strlen(fetch_term(false)) / 2);
    printw("Terminal: %s", fetch_term(false));

    refresh();
    getch();

    leaveok(stdscr, TRUE);
    endwin();
    refresh();
    reset_shell_mode();

    return 0;
}
