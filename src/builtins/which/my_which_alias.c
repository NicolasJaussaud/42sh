/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** my_which_alias
*/

#include "my.h"

int which_alias(alias_t *alias, char *my_input)
{
	alias_t *tmp = alias->next;

	while (tmp) {
		if (strncmp(tmp->aliascommand, my_input,
			strlen(my_input)) == 0) {
			printf("%s:\taliased to %s\n", my_input, tmp->command);
			return (-1);
		}
		tmp = tmp->next;
	}
	return (0);
}