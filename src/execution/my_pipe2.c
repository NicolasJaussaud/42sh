/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** pipe
*/

#include "my.h"

char *my_strcat1(char *dest, char *src)
{
	int i = strlen(dest);
	int j = 0;

	while (src[j] != '\0') {
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *initav(char *av, int count, char **tab)
{
	for (int i = 0; i != count; i++) {
		av = my_strcat1(av, tab[i]);
		av = my_strcat1(av, " ");
	}
	return (av);
}

char *initap(char *ap, int count, char **tab)
{
	for (int i = count + 1; tab[i] != NULL; i++) {
		ap = my_strcat1(ap, tab[i]);
		ap = my_strcat1(ap, " ");
	}
	return (ap);
}