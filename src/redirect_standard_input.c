/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** redirect_standard_input
*/

#include "minishell.h"
#include <stdio.h>
#include <wait.h>

void make_input(int fd[2], mini_t *m, int pid1)
{
    pid_t  pid2 = fork();

    if (pid2 < 0)
        return;
    if (pid2 == 0) {
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        make_minishel(m);
        exit(0);
    } else {
        wait(NULL);
        close(fd[0]);
        close(fd[1]);
    }
    wait(NULL);
}

void redirect_standard_input(mini_t *m)
{
    int fd[2];
    pid_t pid1 = 0;
    char *file = read_file(clear_str(m->all_cmd[m->i + 1]));

    m->buffer = clear_str(m->all_cmd[m->i]);
    m->i += 2;
    if (pipe(fd) == -1)
        return;
    pid1 = fork();
    if (pid1 == 0) {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        my_putstr(file);
        exit(0);
    } else
        make_input(fd, m, pid1);
}
