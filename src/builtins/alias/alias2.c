/*
** EPITECH PROJECT, 2018
** alias2
** File description:
** alias2
*/

#include "my.h"

alias_t *suppr_alias_node(alias_t *alias, int count)
{

	alias_t *tmp = alias;
	alias_t *final = alias;
	int i = 0;

	while (tmp->next) {
		if (i == count) {
			final = tmp->next;
			tmp->next = tmp->next->next;
			free(final);
			tmp = alias;
			return (tmp);
		}
		tmp = tmp->next;
		i++;
	}
	return (alias);
}

int verif_list_alias(alias_t *alias, char **my_input)
{
	alias_t *tmp = alias->next;
	int i = 0;

	while (tmp) {
		if (strncmp(tmp->aliascommand, my_input[1],
			strlen(my_input[1])) == 0)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

void add_node_alias(alias_t *alias, char *aliascommand, char *command)
{
	alias_t *new = malloc(sizeof(*new));
	alias_t *tmp = alias;

	if (aliascommand == NULL || command == NULL)
		return;
	new->command = malloc(sizeof(char) * strlen(command) + 1);
	new->aliascommand = malloc(sizeof(char) * strlen(aliascommand) + 1);
	new->command = strcpy(new->command, command);
	new->aliascommand = strcpy(new->aliascommand, aliascommand);
	new->next = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

alias_t *initalias(void)
{
	alias_t *alias = malloc(sizeof(*alias));
	alias->next = NULL;
	return (alias);
}