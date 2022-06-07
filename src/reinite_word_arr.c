/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** reinite_word_arr
*/

char *reinite_word_arr(char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; ++i) {
        if (buffer[i] == ' ')
            buffer[i] = '$';
        if (buffer[i] == '.')
            buffer[i] = '*';
    }
    return buffer;
}