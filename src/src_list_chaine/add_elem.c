/*
** EPITECH PROJECT, 2022
** add_elem
** File description:
** add_elem
*/

#include "list_chaine.h"

list_t *add_elem(list_t *list, char *value, char *name, int pos)
{
    list_t *prec = list;
    list_t *cur = list;
    int i = 0;

    list_t *cell = create_cell(value, name);
    if (list == NULL)
        return cell;
    if (pos == 0) {
        cell->next = list;
        return cell;
    }
    while (i < pos) {
        i++;
        prec = cur;
        cur = cur->next;
    }
    prec->next = cell;
    cell->next = cur;
    return list;
}
