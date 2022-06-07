/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** str_compare
*/

int my_strlen(char *str);

int str_compare(char *str1, char *str2)
{
    int res = 1;

    if (my_strlen(str1) != my_strlen(str2))
        return (0);
    for (int i = 0; i < my_strlen(str1); i++) {
        if (str1[i] != str2[i])
            res = 0;
    }
    return (res);
}
