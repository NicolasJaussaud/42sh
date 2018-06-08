/*
** EPITECH PROJECT, 2018
** alias_loop
** File description:
** alias_loop
*/

#include "my.h"

int alias_loop2(alias_t *alias, char *aliasc, char *c)
{
	alias_t *tmp = alias->next;

	for (int i = 0; tmp; i++) {
		if (strncmp(tmp->aliascommand, c, strlen(c)) == 0)
			if (strncmp(tmp->command, aliasc, strlen(c)) == 0)
				return (-1);
		tmp = tmp->next;
	}
	return (0);
}

int alias_loop(alias_t *alias, char **my_input)
{
	alias_t *tmp = alias->next;

	for (int i = 0; tmp; i++) {
		if (strncmp(tmp->aliascommand, my_input[0],
			strlen(my_input[0])) == 0)
			if (alias_loop2(alias, tmp->aliascommand,
				tmp->command) == -1)
				return (-1);
		tmp = tmp->next;
	}
	return (0);
}