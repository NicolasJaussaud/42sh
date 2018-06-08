/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** parseur
*/

#include "my.h"

int parseur5(char *my_input, int i, list_t *list)
{
	char **apres;

	if (my_input[i] == '>' && my_input[i + 1] != '>') {
		apres = cut_stringap(my_input, i);
		redir_right(my_input, apres, list);
		free(apres);
		return (0);
	}
	if (my_input[i] == '>' && my_input[i + 1] == '>') {
		apres = cut_stringap(my_input, i);
		double_redir_right(my_input, apres, list);
		free(apres);
		return (0);
	}
	return (-1);
}

int parseur4(char *my_input, int i, list_t *list, alias_t *alias)
{
	char **apres;
	int ret = 0;

	if (my_input[i] == '|') {
		my_pipe(my_input, alias, list);
		return (0);
	}
	if (my_input[i] == '<' && my_input[i + 1] != '<') {
		apres = cut_stringap(my_input, i);
		redir_left(my_input, apres, list);
		free(apres);
		return (0);
	}
	if ((ret = parseur5(my_input, i, list)) != -1) {
		return (0);
	}
	return (-1);
}

int parseur3(list_t *list, alias_t *alias, char *my_input)
{
	int ret = 0;

	if (my_input == NULL)
		return (1);
	for (int i = 0; my_input[i] != '\0'; i++)
		if ((ret = parseur4(my_input, i, list, alias)) != -1)
			return (ret);
	if (my_alias(alias, my_input) == 0 &&
		my_repeat(list, alias, my_input) == 0
		&& my_foreach(my_input) == 0 &&
		my_which(list, alias, my_input) == 0 &&
		my_where(list, alias, my_input) == 0) {
		my_exec(list, my_input, alias);
		return (1);
	}
	return (1);
}

int parseur2(list_t *list, alias_t *alias, char **my_input, int i)
{
	static int ret = 1;
	int tmpret = 1;

	if (my_input[i] != NULL) {
		tmpret = ret;
		ret = parseur3(list, alias, my_input[i]);
		if (tmpret == 0 && ret == 1)
			ret = 0;
		i++;
		parseur2(list, alias, my_input, i);
	}
	return (ret);
}

int parseur(list_t *list, alias_t *alias, char *i)
{
	char **my_input = my_str_to_word_array(i, ';');
	int ret = 0;

	if (i == NULL)
		return (0);
	ret = parseur2(list, alias, my_input, 0);
	for (int j = 0; my_input[j] != NULL; j++)
		free(my_input[j]);
	free(my_input);
	return (ret);
}
