/*
** neo-neofetch
** File description:
** main
*/

#include <malloc.h>
#include <ncurses.h>
#include <string.h>
#include <sys/wait.h>

#include "neofetch.h"

int main()
{
    initscr(); // Initialize ncurses

    int rows, cols;
    getmaxyx(stdscr, rows, cols);

    pid_t pid = fork(); // Create a new process

    if (pid == 0) { // Child process
        char command[100];
        sprintf(command, "kitty +kitten icat --place %dx%d@%dx%d %s", cols / 2, rows / 5, 0, 0, "/home/jjeffroy/Documents/pp.jpg"); // Create the command to display the image
        system(command); // Display the image using kitty's image cat feature
        exit(0); // Exit the child process
    } else { // Parent process
        move(0, (COLS / 1.2) - strlen("CPU: ") - strlen(fetch_cpu()) / 2);
        printw("CPU: %s", fetch_cpu());

        move(1, (COLS / 1.2) - strlen("Shell: ") - strlen(fetch_shell(false)) / 2);
        printw("Shell: %s", fetch_shell(false));

        move(2, (COLS / 1.2) - strlen("Terminal: ") - strlen(fetch_term(false)) / 2);
        printw("Terminal: %s", fetch_term(false));

        refresh(); // Update the screen

        waitpid(pid, NULL, 0); // Wait for the child process to finish
    }

    getch();
    endwin();
    reset_shell_mode();

    return 0;
}