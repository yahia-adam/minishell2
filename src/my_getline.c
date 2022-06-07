/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** my_getline
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "minishell.h"

char *my_getline(mini_t *m)
{
    char *buffer;
    size_t bufsize = 32;
    size_t characters;
    int i = 0;

    buffer = malloc(sizeof(char) * bufsize);
    my_putstr(getcwd(NULL, 0));
    my_putstr("$>");
    if ((characters = getline(&buffer, &bufsize, stdin)) == EOF) {
        my_putstr("exit\n");
        exit(0);
    }
    buffer[characters - 1] = '\0';
    if (my_strlen(buffer) == 0)
        buffer = my_getline(m);
    return (buffer);
}
