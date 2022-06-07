/*
** EPITECH PROJECT, 2021
** lsite.c
** File description:
** liste.c
*/

#include "list_chaine.h"
#include "minishell.h"

void display_list(list_t *list)
{
    while (list != NULL) {
        my_putstr(list->name);
        my_putchar('=');
        if (list->value != NULL && my_strcmp("NULL", list->value) == 0)
            my_putstr(list->value);
        list = list->next;
        my_putchar('\n');
    }
}
