/*
** EPITECH PROJECT, 2018
** alias
** File description:
** alias
*/

#include "my.h"

void free_alias(char **my_input)
{
	for (int j = 0; my_input[j] != NULL; j++)
		free(my_input[j]);
	free(my_input);
}

int verrif_globing_alias(char **my_input)
{
	if (my_input[2] == NULL)
		return (0);
	for (int i = 0; my_input[2][i] != '\0'; i++) {
		if (my_input[2][i] == '*' && strlen(my_input[2]) > 1)
			return (-1);
	}
	return (0);
}

void my_alias3(alias_t *alias, char **my_input, int count)
{
	if ((strncmp("alias", my_input[0], 5) == 0) &&
		(strncmp("alias", my_input[1], 5) == 0) &&
		my_input[2] != NULL) {
		printf("alias: Too dangerous to alias that.\n");
		return;
	} else if ((count = verif_list_alias(alias, my_input)) != -1)
		alias = suppr_alias_node(alias, count);
	if (verrif_globing_alias(my_input) == -1) {
		printf("alias: No match.\n");
		return;
	}
	add_node_alias(alias, my_input[1], my_input[2]);
}

void my_alias2(alias_t *alias, char **my_input)
{
	int count = 0;

	if (my_input[1] == NULL && (strncmp("alias", my_input[0], 5) == 0)) {
		print_alias(alias);
		return;
	} else if (strncmp("unalias", my_input[0], 7) == 0) {
		unalias(alias, my_input);
		return;
	}
	my_alias3(alias, my_input, count);
}

int my_alias(alias_t *alias, char *i)
{
	char **my_input = my_str_to_word_array(i, ' ');

	if (my_input[0] == NULL)
		return (0);
	if ((strncmp("alias", my_input[0], 5) == 0) ||
		(strncmp("unalias", my_input[0], 7) == 0)) {
		my_alias2(alias, my_input);
		return (-1);
	}
	if (alias_loop(alias, my_input) == -1) {
		printf("Alias loop.\n");
		return (-1);
	}
	free_alias(my_input);
	return (0);
}