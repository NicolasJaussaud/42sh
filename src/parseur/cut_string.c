/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** cut_string
*/

#include "my.h"

char **cut_stringap(char *my_input, int nb)
{
	char *str = malloc(sizeof(char) * strlen(my_input) - nb + 1);
	char **apres;
	int i = 0;
	int a = 0;

	if (my_input[i + 1] == '>' || my_input[i + 1] == '<')
		nb = nb + 1;
	i = nb;
	for (; my_input[i] != '\0'; i++) {
		str[a] = my_input[i];
		a++;
	}
	str[a] = '\0';
	apres = transformread(str);
	free(str);
	return (apres);
}