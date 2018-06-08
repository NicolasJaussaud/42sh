/*
** EPITECH PROJECT, 2018
** alias
** File description:
** print_alias
*/

#include "my.h"

char *my_strcpy(char *swap, char *alias)
{
	int i = 0;

	while (alias[i] != '\0') {
		swap[i] = alias[i];
		i++;
	}
	return (swap);
}

void fill_in_order(alias_t *alias)
{
	alias_t *tmp = alias->next;
	char *swap;
	char *swapc;
	int count = 0;

	while (tmp->next) {
		if (strcmp(tmp->aliascommand, tmp->next->aliascommand) > 0) {
			swap = tmp->aliascommand;
			tmp->aliascommand = tmp->next->aliascommand;
			tmp->next->aliascommand = swap;
			swapc = tmp->command;
			tmp->command = tmp->next->command;
			tmp->next->command = swapc;
			count++;
		}
		tmp = tmp->next;
	}
	if (count != 0)
		fill_in_order(alias);
}

void print_alias(alias_t *alias)
{
	if (alias->next == NULL)
		return;
	fill_in_order(alias);
	alias_t *tmp = alias->next;

	while (tmp) {
		printf("%s\t%s\n", tmp->aliascommand, tmp->command);
		tmp = tmp->next;
	}
}
