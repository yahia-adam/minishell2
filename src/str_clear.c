/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** str_clear
*/

#include "minishell.h"
#include <stdio.h>
#include <wait.h>

char *make_clear(int nbr_$, char *str)
{
    char *dest = malloc(sizeof(char) * (my_strlen(str) - (nbr_$ - 1)));
    int i = 0;

    for (int j = 0; str[j] != '\0'; ++j) {
        if (str[j] == '*') {
            dest[i] = '.';
            i++;
        } else if (str[j] != '$') {
            dest[i] = str[j];
            i++;
        } else if (str[j] == '$' &&
(i != 0 && i < (my_strlen(str) - (nbr_$)))) {
            dest[i] = ' ';
            i++;
        }
    }
    dest[i] = '\0';
    return (dest);
}

char *clear_str(char *str)
{
    int nbr_$ = 0;

    for (int i = 0; str[i] != '\0'; ++i){
        if (str[i] == '$')
            ++nbr_$;
    }
    return (make_clear(nbr_$, str));
}