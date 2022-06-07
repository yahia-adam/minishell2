/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** my_strcat
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *str1, char *str2)
{
    int len_res = 0;
    int i = 0;
    int j = 0;
    char *res;

    if (str1 == NULL)
        return str2;
    if (str2 == NULL)
        return str1;
    len_res = (my_strlen(str2) + my_strlen(str1));
    res = malloc(sizeof(char) * (len_res + 1));
    for (; str1[i] != '\0'; i++)
        res[i] = str1[i];
    for (; str2[j] != '\0'; j++)
        res[(i + j)] = str2[j];
    res[len_res] = '\0';
    return (res);
}
