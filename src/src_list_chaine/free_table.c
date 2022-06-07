/*
** EPITECH PROJECT, 2022
** list_chaine
** File description:
** free_table
*/

#include "list_chaine.h"

list_t *free_list_chaine(list_t *list)
{
    list_t *tmp;

    if (list == NULL)
        return list;
    while (list != NULL) {
        tmp = list->next;
        free(list->name);
        free(list->value);
        free(list);
        list = tmp;
    }
    return list;
}
