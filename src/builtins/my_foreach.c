/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** foreach
*/

#include "my.h"

void my_foreach2(char **i)
{
	if (i[1] == NULL || i[2] == NULL) {
		printf("foreach: Too few arguments.\n");
		return;
	}
	if (i[1][0] > 47 && i[1][0] < 58) {
		printf("foreach: Variable name must begin with a letter.\n");
		return;
	}
}

int my_foreach(char *i)
{
	char **my_input = my_str_to_word_array(i, ' ');

	if (my_input[0] == NULL)
		return (0);
	if ((strncmp("foreach", my_input[0], 7) == 0)) {
		my_foreach2(my_input);
		return (-1);
	}
	return (0);
}