/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** redirect_cmd_in_string
*/

#include "minishell.h"
#include <stdio.h>
#include <unistd.h>
#include <wait.h>

char *my_getcmd(void)
{
    char *buffer;
    size_t bufsize = 32;
    size_t characters;
    int i = 0;

    buffer = malloc(sizeof(char) * bufsize);
    my_putstr("?");
    if ((characters = getline(&buffer, &bufsize, stdin)) == EOF)
        exit(0);
    buffer[characters - 1] = '\0';
    return (buffer);
}

void display_list_cmd(list_t *list)
{
    while (list != NULL) {
        my_putstr(list->name);
        list = list->next;
        my_putchar('\n');
    }
}

list_t *make_list(mini_t *m)
{
    char *buffer = my_getcmd();
    list_t *l = NULL;
    int i = 1;

    l = add_elem(l, "NULL", buffer, 0);
    if (m->all_cmd[m->i + 1][0] == '$')
        m->all_cmd[m->i + 1] += 1;
    while (my_strcmp(buffer, m->all_cmd[m->i + 1]) != 1) {
        buffer = my_getcmd();
        l = add_elem(l, "NULL", buffer, i);
        i++;
    }
    m->buffer = m->all_cmd[m->i];
    for (int i = 0; m->buffer[i] != '\0'; ++i)
        if (m->buffer[i] == '$')
            m->buffer[i] = ' ';
    m->i += 2;
    return (l);
}

void cmd_in_string(mini_t *m, int pid1)
{
    int pid2 = 0;

    pid2 = fork();
    if (pid2 < 0)
        return;
    if (pid2 == 0)
        make_minishel(m);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}

void redirect_cmd_in_string(mini_t *m)
{
    int pid1 = 0;
    list_t *l = make_list(m);

    pid1 = fork();
    if (pid1 == 0) {
        display_list_cmd(l);
        exit(0);
    }
    cmd_in_string(m, pid1);
}
