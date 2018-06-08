/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** displays
*/

#include "my.h"

void display_char(char c)
{
	write (1, &c, 1);
}

void display_string(char *str)
{
	if (!str)
		return;
	for (int i = 0; str[i] != '\0'; i++)
		display_char(str[i]);
}

void display_array_of_string(char **array)
{
	if (!array)
		return;
	for (int a = 0; array[a] != NULL; a++) {
		display_string(array[a]);
		display_char('\n');
	}
}

int my_strlen(char const *str)
{
	int i = 0;

	if (!str)
		return (84);
	while (str[i] != '\0')
		i++;
	return (i);
}

int my_strlen_array(char **str)
{
	int i = 0;

	if (!str)
		return (84);
	while (str[i] != NULL)
		i++;
	return (i);
}
