/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** minishell2
*/

#include "my.h"

int separator(char const *inpute_1, char inpute_2)
{
	int nb = 0;
	for (int x = 0; inpute_1[x] != '\0'; x++) {
		if (inpute_1[x] == inpute_2 || inpute_1[x] == '\n')
			nb++;
	}
	return (nb);
}

void stock_str(char **new_str, char const *str, char sep)
{
	int line = 0;
	int cols = 0;

	for (int i = 0; str[i] != '\0'; i++, cols++) {
		if (i == '\0')
			new_str[line] = malloc(sizeof(char) *
				(strlen(str) + 1));
		if (str[i] == sep || str[i] == '\n') {
			new_str[line][cols] = '\0';
			(line)++;
			new_str[line] = malloc(sizeof(char) *
				strlen(str) + 1);
			cols = -1;
		} else
			new_str[line][cols] = str[i];
	}
	new_str[line][cols] = '\0';
	new_str[line + 1] = NULL;
}

char **my_str_to_word_tab(char *str, char sep)
{
	int nb_word = 0;
	char **new_str = NULL;

	if (str == NULL || str[0] == 0)
		return (NULL);
	nb_word = separator(str, sep);
	new_str = malloc(sizeof(char *) * (nb_word + 2));
	stock_str(new_str, str, sep);
	return (new_str);
}
