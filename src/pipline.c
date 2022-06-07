/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** pipline
*/

#include "minishell.h"
#include <wait.h>

void inter_pip(int fd[2], int pid1, mini_t *m)
{
    int pid2 = 0;
    pid2 = fork();
    if (pid2 < 0)
        return;
    if (pid2 == 0) {
        m->buffer = clear_str(m->all_cmd[m->i]);
        m->i++;
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        make_minishel(m);
        exit(0);
    }
    close(fd[1]);
    close(fd[0]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}

void pipe_command(mini_t *m)
{
    int fd[2];
    int pid1 = 0;

    m->buffer = clear_str(m->all_cmd[m->i]);
    m->i++;
    if (pipe(fd) == -1)
        return;
    pid1 = fork();
    if (pid1 == 0) {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        make_minishel(m);
        exit(0);
    }
    inter_pip(fd, pid1, m);
}

int count_nbr_pip(mini_t *m)
{
    int nbr_pip = 1;

    while (m->l != NULL) {
        if (my_strcmp(m->l->name, "|") != 1)
            break;
        nbr_pip++;
        m->l = m->l->next;
    }
    return (nbr_pip);
}

void make_interpipe(int fdd, int fd[2], mini_t *m, int nbr_pip)
{
    dup2(fdd, 0);
    if (nbr_pip != 1)
            dup2(fd[1], 1);
    close(fd[0]);
    m->buffer = clear_str(m->all_cmd[m->i]);
    make_minishel(m);
}

void wait_and_close(mini_t *m, int fd[2])
{
    wait(NULL);
    close(fd[1]);
    m->i++;
}

void make_pipline(mini_t *m)
{
    int fd[2];
    pid_t pid;
    int fdd = 0;
    int i = 0;
    int nbr_pip = count_nbr_pip(m);

    if (nbr_pip == 2) {
        pipe_command(m);
        return;
    }
    while (nbr_pip != 0) {
        pipe(fd);
        if ((pid = fork()) == -1)
            exit(1);
        else if (pid == 0) {
            make_interpipe(fdd, fd, m, nbr_pip);
            exit(1);
        } else {
            wait_and_close(m, fd);
            fdd = fd[0];
        }
        nbr_pip--;
    }
}
