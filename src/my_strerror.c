/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** my_strerror
*/

#include "minishell.h"
#include <errno.h>
#include <string.h>

void my_strerror(char *str)
{
    my_putstr(str);
    my_putstr(": ");
    my_putstr(strerror(errno));
    my_putstr(".\n");
}