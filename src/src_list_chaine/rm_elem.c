/*
** EPITECH PROJECT, 2022
** list_chaine
** File description:
** rm_elem
*/

#include "list_chaine.h"

list_t *rm_elem_(int pos, list_t *cur, list_t *prec, list_t *list)
{
    int i = 0;

    while (i < pos) {
        i++;
        prec = cur;
        cur = cur->next;
    }
    prec->next = cur->next;
    free(cur->name);
    free(cur->value);
    free (cur);
    return list;
}

list_t *rm_elem(list_t *list, int pos)
{
    list_t *prec = list;
    list_t *cur = list;

    if (list == NULL)
        return NULL;
    if (pos == 0) {
        list = list->next;
        free(cur->name);
        free(cur->value);
        free(cur);
        return (list);
    }
    list = rm_elem_(pos, cur, prec, list);
    return (list);
}
