/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** my_put
*/

#include<unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    int i = 0;

    if (str == NULL) {
        my_putstr("NULL\n");
        return;
    }
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}

void my_putnbr(int n)
{
    int nb;

    if (n < 0) {
        my_putchar('-');
        n *= -1;
        my_putnbr(n);
        return;
    } else if (n > 9)
        my_putnbr(n / 10);
    nb = n % 10;
    my_putchar(nb + '0');
    return;
}

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    if (str[0] == '\0')
        return (0);
    while (str[i] != '\0')
        i = i + 1;
    return (i);
}
