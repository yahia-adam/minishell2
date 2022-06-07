/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** free_list
*/

#include <stdlib.h>

char **free_list(char **arr)
{
    for (int i = 0; arr[i] != NULL ; i++)
        free(arr[i]);
    free(arr);
    return (arr);
}
