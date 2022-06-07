/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** get_file_type
*/

#include <sys/stat.h>
#include "minishell.h"

int getfile_type(char *filename)
{
    struct stat buf;

    if (filename[0] == '.' && filename[1] == '/')
        filename += 2;
    if ((stat(filename, &buf) == -1))
        return (0);
    if (S_ISREG(buf.st_mode))
        return 1;
    if (S_ISDIR(buf.st_mode))
        return 2;
    return 0;
}
