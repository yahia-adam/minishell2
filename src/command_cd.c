/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** command_cd
*/

#include <unistd.h>
#include "minishell.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>

void make_cd_home(mini_t *m)
{
    if (chdir(get_elem(m->lenv, "HOME")) == 0) {
        modif_elem(m->lenv, getcwd(NULL, 0), "PWD");
        return;
    } else
        my_strerror(get_elem(m->lenv, "HOME"));
}

void cd_begin_in_home(mini_t *m)
{
    char *str = NULL;

    m->argv[1] += 1;
    str = my_strcat(get_elem(m->lenv, "HOME"), m->argv[1]);
    if (chdir(str) == 0) {
        modif_elem(m->lenv, getcwd(NULL, 0), "PWD");
        return;
    } else
        my_strerror(str);
}

void make_cd_with_path(char *oldpwd, mini_t *m, char *pwd)
{
    if (chdir(m->argv[1]) == 0) {
        if (get_elem(m->lenv, "PWD") == NULL)
            m->lenv = add_elem(m->lenv, getcwd(NULL, 0), "PWD", 0);
        else
            modif_elem(m->lenv, getcwd(NULL, 0), "PWD");
        if (oldpwd == NULL)
            m->lenv = add_elem(m->lenv, pwd, "OLDPWD", 0);
        else
            modif_elem(m->lenv, pwd, "OLDPWD");
        return;
    } else
        my_strerror(m->argv[1]);
}

void cd_with_path_and_cd_old(mini_t *m)
{
    char *oldpwd;
    char *pwd;

    if (get_elem(m->lenv, "PWD") == NULL)
        m->lenv = add_elem(m->lenv, getcwd(NULL, 0), "PWD", 0);
    oldpwd = get_elem(m->lenv, "OLDPWD");
    pwd = get_elem(m->lenv, "PWD");
    if (my_strcmp(m->argv[1], "-") == 1) {
        if (oldpwd == NULL) {
            my_putstr(": No such file or directory.\n");
            return;
        } else if (chdir(oldpwd) == -1) {
            my_strerror(oldpwd);
            return;
        }
        modif_elem(m->lenv, oldpwd, "PWD");
        modif_elem(m->lenv, pwd, "OLDPWD");
        return;
    }
    make_cd_with_path(oldpwd, m, pwd);
}

int make_my_cd(mini_t *m)
{
    char *str;

    if (m->argv[1] == NULL)
        make_cd_home(m);
    else if (m->argv[1][0] == '~')
        cd_begin_in_home(m);
    else
        cd_with_path_and_cd_old(m);
    return (1);
}
