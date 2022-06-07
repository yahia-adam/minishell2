/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** create_funtion
*/

#include "minishell.h"
#include <stddef.h>
#include <stdlib.h>

pointer *create_function(void)
{
    pointer *p = malloc(sizeof(pointer) * 7);

    p[0].pointer = &make_semicolons;
    p[0].str = ";";
    p[1].pointer = &make_pipline;
    p[1].str = "|";
    p[2].pointer = &redirect_standard_out_to_a_new_file;
    p[2].str = ">";
    p[3].pointer = &append_standard_out_to_an_existing_file;
    p[3].str = ">>";
    p[4].pointer = &redirect_standard_input;
    p[4].str = "<";
    p[5].pointer = &redirect_cmd_in_string;
    p[5].str = "<<";
    p[6].pointer = NULL;
    p[6].str = NULL;
    return (p);
}
