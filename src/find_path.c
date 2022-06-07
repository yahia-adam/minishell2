/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** find_path
*/

#include <unistd.h>
#include "minishell.h"

char *make_interpath(char **arr_path, char *str, char work_directory[256])
{
    char *path;
    int z = 1;

    for (int i = 0; arr_path[i] != NULL; i++) {
        chdir(arr_path[i]);
        if (access(str, F_OK) == 0) {
            chdir(work_directory);
            path = my_strcat(arr_path[i], "/");
            path = my_strcat(path, str);
            return (path);
        }
    }
    chdir(work_directory);
    return (".");
}

char *find_path(mini_t *m, char *str)
{
    char *path;
    char **arr_path;
    char *work_directory;

    path = get_elem(m->lenv, "PATH");
    if (path == NULL)
        return (".");
    arr_path = my_str_to_word_arr(path, ":");
    work_directory = getcwd(NULL, 0);
    return (make_interpath(arr_path, str, work_directory));
}
