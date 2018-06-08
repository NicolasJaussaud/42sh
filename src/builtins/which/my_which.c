/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** my_which
*/

#include "my.h"

void my_which_function(list_t *list, alias_t *alias, char *my_input)
{
	char *i = malloc(sizeof(char) * strlen(my_input) + 7);
	int j = 6;

	i[0] = 'w';
	i[1] = 'h';
	i[2] = 'i';
	i[3] = 'c';
	i[4] = 'h';
	i[5] = ' ';
	if (which_builtins(my_input) == -1)
		return;
	else if (which_alias(alias, my_input) == -1)
		return;
	else {
		for (int a = 0; my_input[a] != '\0'; j++, a++)
			i[j] = my_input[a];
		i[j] = '\0';
		my_exec(list, i, alias);
	}
	free(i);
}

void my_which2(list_t *list, alias_t *alias, char **my_input)
{
	if (my_input[1] == NULL) {
		printf("which: Too few arguments.\n");
		return;
	}
	for (int i = 1; my_input[i] != NULL; i++)
		my_which_function(list, alias, my_input[i]);
}

int my_which(list_t *list, alias_t *alias, char *i)
{
	char **my_input = my_str_to_word_array(i, ' ');

	if (my_input[0] == NULL)
		return (0);
	if ((strncmp("which", my_input[0], 5) == 0)) {
		my_which2(list, alias, my_input);
		return (-1);
	}
	for (int j = 0; my_input[j] != NULL; j++)
		free(my_input[j]);
	free(my_input);
	return (0);
}