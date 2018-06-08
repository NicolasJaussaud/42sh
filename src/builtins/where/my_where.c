/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** my_were
*/

#include "my.h"

void my_where_function(list_t *list, alias_t *alias, char *my_input)
{
	char *i = malloc(sizeof(char) * strlen(my_input) + 7);
	int j = 6;

	i[0] = 'w';
	i[1] = 'h';
	i[2] = 'e';
	i[3] = 'r';
	i[4] = 'e';
	i[5] = ' ';
	if (where_builtins(my_input) == -1)
		return;
	else if (where_alias(alias, my_input) == -1)
		return;
	else {
		for (int a = 0; my_input[a] != '\0'; j++, a++)
			i[j] = my_input[a];
		i[j] = '\0';
		my_exec(list, i, alias);
	}
	free(i);
}

void my_where2(list_t *list, alias_t *alias, char **my_input)
{
	if (my_input[1] == NULL) {
		printf("where: Too few arguments.\n");
		return;
	}
	for (int i = 1; my_input[i] != NULL; i++)
		my_where_function(list, alias, my_input[i]);
}

int my_where(list_t *list, alias_t *alias, char *i)
{
	char **my_input = my_str_to_word_array(i, ' ');

	if (my_input[0] == NULL)
		return (0);
	if ((strncmp("where", my_input[0], 5) == 0)) {
		my_where2(list, alias, my_input);
		return (-1);
	}
	for (int j = 0; my_input[j] != NULL; j++)
		free(my_input[j]);
	free(my_input);
	return (0);
}