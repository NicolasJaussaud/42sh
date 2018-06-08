/*
** EPITECH PROJECT, 2018
** unalias
** File description:
** unalias
*/

#include "my.h"

int unalias_verif(alias_t *alias, char *command)
{
	alias_t *tmp = alias->next;
	int i = 0;

	while (tmp) {
		if (strncmp(tmp->aliascommand, command, strlen(command)) == 0) {
			return (i);
		}
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

void unalias(alias_t *alias, char **my_input)
{
	int ret = 0;

	if (my_input[1] == NULL) {
		printf("unalias: Too few arguments.\n");
		return;
	}
	for (int i = 1; my_input[i] != NULL; i++) {
		if ((ret = unalias_verif(alias, my_input[i])) != -1) {
			alias = suppr_alias_node(alias, ret);
		}
	}
}