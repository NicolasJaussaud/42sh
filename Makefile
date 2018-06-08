##
## EPITECH PROJECT, 2018
## epitech
## File description:
## Makefile
##

SRC	=	./lib/displays.c		\
		./lib/my_getnbr.c		\
		./lib/my_strcat.c		\
		./lib/my_strcmp.c		\
		./lib/my_str_to_word_array.c \
		./lib/my_strdup.c		\
		./lib/my_strncmp.c		\
		./lib/my_str_to_word_tab.c	\
		./lib/clear_string.c \
		./lib/my_str_to_word_tab2.c \
		./src/builtins/echo/my_echo.c		\
		./src/builtins/echo/my_echo2.c		\
		./src/builtins/my_cd.c		\
		./src/builtins/builtins_2.c		\
		./src/builtins/my_setenv.c		\
		./src/builtins/alias/alias.c \
		./src/builtins/alias/alias2.c \
		./src/builtins/alias/alias_loop.c \
		./src/builtins/alias/print_alias.c \
		./src/builtins/alias/unalias.c \
		./src/builtins/my_repeat.c \
		./src/builtins/my_foreach.c \
		./src/builtins/which/my_which.c \
		./src/builtins/which/my_which_builtins.c \
		./src/builtins/which/my_which_alias.c \
		./src/builtins/where/my_where.c \
		./src/builtins/where/my_where_builtins.c \
		./src/builtins/where/my_where_alias.c \
		./src/execution/path_handler.c		\
		./src/execution/pointer_type.c		\
		./src/execution/my_execs.c		\
		./src/execution/my_pipe.c \
		./src/execution/my_pipe2.c \
		./src/execution/redirection_right.c \
		./src/execution/redirection_left.c \
		./src/execution/double_redirection_right.c \
		./src/execution/exec_redir.c \
		./src/list/init_list.c		\
		./src/list/linked_list.c		\
		./src/list/linked_list_2.c		\
		./src/list/my_strlen_for_list.c	\
		./src/parseur/parseur.c \
		./src/parseur/cut_string.c \
		./src/utils/main.c			\
		./src/utils/my_pront.c		\
		./src/utils/check_signal.c \

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	=	-W -Wall -Wextra -Iinclude

NAME	=	42sh

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
