/*
** EPITECH PROJECT, 2018
** MY
** File description:
** lib
*/
#include "my.h"

char	*my_strcat(char *str_a, char *str_b)
{
	char *str = NULL;
	int x = 0;
	int y = 0;

	if (str_a == NULL || str_b == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (my_strlen(str_a) + my_strlen(str_b) + 1));
	for (x = 0; x < my_strlen(str_a); x++)
		str[x] = str_a[x];
	for (y = 0; y < my_strlen(str_b); y++) {
		str[x] = str_b[y];
		x++;
	}
	str[x] = '\0';
	return (str);
}
