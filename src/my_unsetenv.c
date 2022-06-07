/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** my_unsetenv
*/

#include <stdlib.h>
#include "minishell.h"

char *malloc_str(char *str)
{
    int len_str = 0;
    char *dest;

    for (; str[len_str] != '\0'; len_str++);
    dest = malloc(sizeof(char) * (len_str + 1));
    for (int i = 0; str[i] != '\0'; i++)
        dest[i] = str[i];
    dest[len_str] = '\0';
    return (dest);
}

int my_unsetenv(mini_t *m)
{
    int pos = 0;
    list_t *tmp = m->lenv;

    if (m->argv[1] == NULL) {
        my_putstr("unsetenv: Too few arguments.\n");
        return 1;
    }
    for (int i = 1; m->argv[i] != NULL; ++i) {
        tmp = m->lenv;
        pos = 0;
        while (tmp != NULL) {
            if (my_strcmp(tmp->name, m->argv[i]) == 1)
                rm_elem(m->lenv, pos);
            tmp = tmp->next;
            pos++;
        }
    }
    return (1);
}