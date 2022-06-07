/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** list_chaine
*/

#ifndef LINKED_LIST_H_
    #define LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct list_s {
    char *value;
    char *name;
    struct list_s *next;
} list_t;

void my_putnbr(int n);
void my_putchar(char c);
int my_getnbr(char const *str);
void my_putstr(char const *str);
list_t *create_cell(char *value, char *name);
void modif_elem(list_t *l, char *value, char *name);
list_t *rm_elem(list_t *l, int pos);
list_t *add_elem(list_t *l, char *value, char *name, int pos);
char *get_elem(list_t *l, char *name);
list_t *free_list_chaine(list_t *list);
void display_list(list_t *l);
char *my_strdup(char *str);
int my_strcmp(char const *s1, char const *s2);
#endif/*!LINKED_LIST_H_*/