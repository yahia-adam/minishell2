/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** strcat
*/

int my_strlen(char const *str);

char * my_strcat ( char * dest , char const * src )
{
    int i = 0;
    int j = my_strlen(dest);

    while (src[i] != '\0') {
        dest[j] = src[i];
        i = i + 1;
        j = j + 1;
    }
    return (dest);
}
