/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** verif_seg
*/

#include "minishell.h"
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void verif_seg(int state, mini_t *m)
{
    char *str = NULL;

    if (state == 11) {
        str = strsignal(state);
        my_putstr(str);
        modif_elem(m->lenv, "11", "DISPLAY");
    } else if (WCOREDUMP(state)) {
        my_putstr("Segmentation fault (core dumped)\n");
        modif_elem(m->lenv, "139", "DISPLAY");
    }
    if (getfile_type(m->argv[0]) == 2) {
        if (m->argv[0][0] == '.' && m->argv[0][1] == '/') {
            my_putstr(m->argv[0]);
            my_putstr(": Permission denied.\n");
            modif_elem(m->lenv, "1", "DISPLAY");
        }
    }
    free_list(m->argv);
}
