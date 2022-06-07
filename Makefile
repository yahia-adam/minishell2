##
## EPITECH PROJECT, 2022
## minishell2
## File description:
## Makefile
##

SRC		=	src/main_mysh.c				\
			src/my_put.c				\
			src/my_str_to_world_arr.c	\
			src/my_getline.c			\
			src/minishel.c				\
			src/my_strcat.c				\
			src/str_compare.c			\
			src/free_list.c				\
			src/command_cd.c			\
			src/find_path.c				\
			src/my_setenv.c				\
			src/my_unsetenv.c			\
			src/print_env.c				\
			src/echo_dollar.c			\
			src/verif_seg.c				\
			src/get_file_type.c			\
			src/append_standard_out_to_an_existing_file.c\
			src/create_funtion.c\
			src/pipline.c\
			src/redirect_cmd_in_string.c\
			src/redirect_standard_input.c\
			src/redirect_standard_out_to_a_new_file.c\
			src/semicolons.c\
			src/src_list_chaine/add_elem.c\
			src/src_list_chaine/create_elem.c\
			src/src_list_chaine/display_table.c\
			src/src_list_chaine/free_table.c\
			src/src_list_chaine/get_elem.c\
			src/src_list_chaine/modif_elem.c\
			src/src_list_chaine/rm_elem.c\
			src/my_strcmp.c\
			src/read_file.c\
			src/reinite_word_arr.c\
			src/ambiguous_output_redirect.c\
			src/pars_cmd.c\
			src/bultin.c\
			src/str_clear.c\
			src/my_strerror.c\

SRC_TEST = src/my_put.c					\

OBJ		=	$(SRC:.c=.o)

NAME	= 	mysh

CPPFLAGS = -I ./include

all:	$(OBJ)
		gcc -o $(NAME) $(OBJ)

tests_run:
		gcc -o test $(SRC_TEST) ./tests/test_minishel.c \
		--coverage -lcriterion
		./test

debug: CFLAGS += -g
debug: re

clean:
	rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all
