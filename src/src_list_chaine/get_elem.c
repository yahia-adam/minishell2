/*
** EPITECH PROJECT, 2022
** list_chaine
** File description:
** get_elem
*/

#include "list_chaine.h"

char *get_elem(list_t *list, char *name)
{
    int i = 0;

    if (list == NULL)
        return 0;
    while (list != NULL) {
        if (my_strcmp(list->name, name) == 1)
            return (list->value);
        list = list->next;
    }
    return (NULL);
}
