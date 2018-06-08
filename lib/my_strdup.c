/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** strdup
*/

#include "my.h"

char	*my_strdup(char *src)
{
	int i = 0;
	char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));

	if (dest == NULL)
		return (NULL);
	for (; src[i] != '\0'; i++) {
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}