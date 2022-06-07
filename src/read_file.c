/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** read_file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int my_strlen(char const *str);

int get_file_size(const char *filename)
{
    int i = 0;
    struct stat st;

    i = stat(filename, &st);
    i = st.st_size;
    return (i);
}

char *read_file(char *filepath)
{
    struct stat file;
    int fd;
    int len_read;
    char *buffer;

    buffer = malloc(sizeof(char) * (get_file_size(filepath) + 1));
    if ((lstat(filepath, &file) == -1) || ( S_ISREG( file.st_mode ) == 0))
        return NULL;
    if (buffer == NULL)
        return (NULL);
    fd = open(filepath, O_RDONLY);
    if (fd == - 1)
        return (NULL);
    len_read = read(fd, buffer, get_file_size(filepath));
    if (len_read == -1)
        return (NULL);
    if (my_strlen(buffer) == 0)
        return (NULL);
    buffer[get_file_size(filepath)] = '\0';
    return (buffer);
}
