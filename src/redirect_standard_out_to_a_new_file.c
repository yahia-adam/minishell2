/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** redirect_standard_out_to_a_new_file
*/

#include "minishell.h"
#include <stdio.h>
#include <wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void redirect_standard_out_to_a_new_file(mini_t *m)
{
    int pid1 = 0;
    int file = open
    (clear_str(m->all_cmd[m->i + 1]), O_TRUNC | O_RDWR | O_CREAT, 0644);

    m->buffer = clear_str(m->all_cmd[m->i]);
    m->i += 2;
    pid1 = fork();
    if (pid1 == 0) {
        dup2(file, STDOUT_FILENO);
        close(file);
        make_minishel(m);
        exit(0);
    }
    close(file);
    waitpid(pid1, NULL, 0);
}
