/*
** EPITECH PROJECT, 2018
** MY
** File description:
** lib
*/

#include "my.h"

int my_getnbr(char *str)
{
	int i = 0;
	int x = 1;
	int result = 0;

	if (!str)
		return (84);
	while (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-')
			x = -x;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str [i] <= '9') {
		result = result*10 + str[i] - 48;
		i++;
	}
	if (x == -1)
		result = -result;
	return (result);
}