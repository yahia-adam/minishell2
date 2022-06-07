/*
** EPITECH PROJECT, 2022
** add_elem
** File description:
** addelem
*/

#include "list_chaine.h"

void modif_elem(list_t *list, char *value, char *name)
{
    int i = 0;

    if (list == NULL)
        return;
    while (list != NULL) {
        if (my_strcmp(list->name, name) == 1)
            list->value = value;
        list = list->next;
    }
}
