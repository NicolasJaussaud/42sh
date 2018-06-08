/*
** EPITECH PROJECT, 2018
** clear_string
** File description:
** .c
*/

#include "my.h"

char *clear_string(char *str)
{
	int i = 0;

	for (i = 0; (str[i] == ' ' || str[i] == '\t'); i++);
	if (i == my_strlen(str))
		return (NULL);
	return (str);
}