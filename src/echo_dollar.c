/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** echo_dollar
*/

#include <stddef.h>
#include "minishell.h"

int echo_dollar(mini_t *m)
{
    char *dest =  get_elem(m->lenv, "DISPLAY");

    if (dest == NULL)
        return (1);
    if (dest[0] == ':')
        dest += 1;
    my_putstr(dest);
    my_putchar('\n');
    return (1);
}
