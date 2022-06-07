/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** my_str_to_world_arr
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "minishell.h"

int str_compare(char *str1, char *str2);

char **do_my_array(char *str, char **arr, int len_arr, char c)
{
    int len_str = 0;
    int n = 0;

    for (int i = 0; i != len_arr; i++) {
        for (; (str[len_str] != c && str[len_str] != '\0'); len_str++);
        arr[i] = malloc(sizeof(char) * (len_str + 1));
        arr[i][len_str] = '\0';
        for (int z = 0; (str[z] != c && str[z] != '\0') ; z++)
            arr[i][z] = (str[z]);
        str += (len_str + 1);
        len_str = 0;
    }
    return (arr);
}

char dest_i(char *str, char *str2, int i)
{
    int tmp = 0;
    for (int m = 0; str2[m] != '\0'; m++) {
        if (str[i] == str2[m]) {
            return ' ';
            tmp = 1;
        }
    }
    for (int z = 7; z != 14; z++) {
        if (str[i] == z) {
            return ' ';
            tmp = 1;
        }
    }
    if (tmp == 0)
        return (str[i]);
}

char *handling_space_tab(char *str, char *str2)
{
    int i = 0;
    char *dest;

    dest = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (i = 0; str[i] != '\0'; i++) {
        dest[i] = dest_i(str, str2, i);
    }
    dest[i] = '\0';
    return (dest);
}

char **ar_arrange(char **arr)
{
    char **dest;
    int d = 0;
    int len_dest = 0;

    for (int i = 0; arr[i] != NULL; i++) {
        if (arr[i][0] != '\0') {
            len_dest ++;
        }
    }
    dest = malloc(sizeof(char*) * (len_dest + 1));
    for (int i = 0; arr[i] != NULL; i++) {
        if (arr[i][0] != '\0') {
            dest[d] = arr[i];
            d++;
        } else
            free(arr[i]);
    }
    dest[d] = NULL;
    return (dest);
}

char **my_str_to_word_arr(char *str, char *str2)
{
    int len_arr = 1;
    char **arr;
    int i = 0;

    if (str[0] == '\0') {
        arr = NULL;
        return (arr);
    }
    for (i = 0; (str[i] != '\0') && (str[i] == ' ' || str[i] == '\t'); i++);
    str += i;
    str = handling_space_tab(str, str2);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            len_arr++;
    }
    arr = malloc(sizeof(char*) * (len_arr + 1));
    arr[len_arr] = NULL;
    arr = do_my_array(str, arr, len_arr, ' ');
    arr = ar_arrange(arr);
    return (arr);
}
