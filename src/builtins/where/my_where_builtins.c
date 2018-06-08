/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** my_where_builtins
*/

#include "my.h"

int where_builtins3(char *my_input)
{
	if ((strncmp("alias", my_input, 5) == 0)) {
		printf("alias is a shell built-in\n");
		return (-1);
	} else if ((strncmp("unalias", my_input, 7) == 0)) {
		printf("unalias is a shell built-in\n");
		return (-1);
	}
	if (strncmp("repeat", my_input, 6) == 0) {
		printf("repeat is a shell built-in\n");
		return (-1);
	}
	return (0);
}

int where_builtins2(char *my_input)
{
	int ret = 0;

	if ((strncmp("setenv", my_input, 6) == 0)) {
		printf("setenv is a shell built-in\n");
		return (-1);
	} else if ((strncmp("unsetenv", my_input, 8) == 0)) {
		printf("unsetenv is a shell built-in\n");
		return (-1);
	}
	if (strncmp("exit", my_input, 4) == 0) {
		printf("exit is a shell built-in\n");
		return (-1);
	}
	ret = where_builtins3(my_input);
	return (ret);
}

int where_builtins(char *my_input)
{
	if ((strncmp("echo", my_input, 4) == 0)) {
		printf("echo is a shell built-in\n");
		return (-1);
	} else if ((strncmp("cd", my_input, 2) == 0)) {
		printf("cd is a shell built-in\n");
		return (-1);
	}
	if ((strncmp("env", my_input, 3) == 0)) {
		printf("env is a shell built-in\n");
		return (-1);
	} else if (where_builtins2(my_input) == -1)
		return (-1);
	return (0);
}