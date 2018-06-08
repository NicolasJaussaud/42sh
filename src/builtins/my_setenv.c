/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** my_setenv
*/

#include "my.h"

int gest_of_setenv(char **i)
{
	if ((i[1][0] >= 'a' && i[1][0] <= 'z') ||
		(i[1][0] >= 'A' && i[1][0] <= 'Z')) {
		return (0);
	} else
		return (1);
}

int display_my_error(char **i)
{
	display_string(i[0]);
	display_string(": Variable name must begin with a letter.\n");
	return (1);
}

int my_setenv(list_t *list, char **i)
{
	char *a = NULL;
	char *b = NULL;

	if (i[1] == NULL) {
		my_env(list, i);
		return (0);
	}
	if (gest_of_setenv(i) == 0) {
		a = my_strcat(i[1], "=");
		if (i[2] != NULL) {
			b = my_strcat(a, i[2]);
			push_back(list, b);
		} else {
			b = my_strcat(a, "");
			push_back(list, b);
		}
		return (0);
	} else {
		display_my_error(i);
		return (1);
	}
}
