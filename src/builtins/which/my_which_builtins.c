/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** my_which_builtins
*/

#include "my.h"

int which_builtins4(char *my_input)
{
	if ((strncmp("where", my_input, 5) == 0)) {
		printf("where: shell built-in command.\n");
		return (-1);
	} else if ((strncmp("unsetenv", my_input, 8) == 0)) {
		printf("unsetenv: shell built-in command.\n");
		return (-1);
	}
	if (strncmp("exit", my_input, 4) == 0) {
		printf("exit: shell built-in command.\n");
		return (-1);
	}
	return (0);
}

int which_builtins3(char *my_input)
{
	int ret = 0;

	if ((strncmp("alias", my_input, 5) == 0)) {
		printf("alias: shell built-in command.\n");
		return (-1);
	} else if ((strncmp("unalias", my_input, 7) == 0)) {
		printf("unalias: shell built-in command.\n");
		return (-1);
	}
	if (strncmp("repeat", my_input, 6) == 0) {
		printf("repeat: shell built-in command.\n");
		return (-1);
	}
	ret = which_builtins4(my_input);
	return (ret);
}

int which_builtins2(char *my_input)
{
	int ret = 0;

	if ((strncmp("setenv", my_input, 6) == 0)) {
		printf("setenv: shell built-in command.\n");
		return (-1);
	} else if ((strncmp("unsetenv", my_input, 8) == 0)) {
		printf("unsetenv: shell built-in command.\n");
		return (-1);
	}
	if (strncmp("exit", my_input, 4) == 0) {
		printf("exit: shell built-in command.\n");
		return (-1);
	}
	ret = which_builtins3(my_input);
	return (ret);
}

int which_builtins(char *my_input)
{
	if ((strncmp("echo", my_input, 4) == 0)) {
		printf("echo: shell built-in command.\n");
		return (-1);
	} else if ((strncmp("cd", my_input, 2) == 0)) {
		printf("cd: shell built-in command.\n");
		return (-1);
	}
	if ((strncmp("env", my_input, 3) == 0)) {
		printf("env: shell built-in command.\n");
		return (-1);
	} else if (which_builtins2(my_input) == -1)
		return (-1);
	return (0);
}