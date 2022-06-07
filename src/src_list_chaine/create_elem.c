/*
** EPITECH PROJECT, 2022
** list_chaine
** File description:
** create_elem
*/

#include "list_chaine.h"

list_t *create_cell(char *value, char *name)
{
    list_t *cell = malloc(sizeof(list_t));

    if (cell == NULL)
        return NULL;
    if (name != NULL)
        cell->name = my_strdup(name);
    else
        cell->name = NULL;
    if (value != NULL)
        cell->value = my_strdup(value);
    else
        cell->value = NULL;
    cell->next = NULL;
    return (cell);
}
