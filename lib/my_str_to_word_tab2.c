/*
** EPITECH PROJECT, 2018
** filltab
** File description:
** filltab
*/

#include "my.h"

int wordcount2(char *str)
{
	int word = 0;
	int i = 0;

	while (str[i] != '\0') {
		if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 &&
			str[i] <= 122)
			|| (str[i] >= 48 && str[i] <= 57))
			if (!((str[i + 1] >= 65 && str[i + 1] <= 90) ||
				(str[i + 1] >= 97 && str[i + 1] <= 122) ||
				(str[i + 1] >= 48 && str[i + 1] <= 57)))
				word++;
		i++;
	}
	return (word);
}

char **fill_letters3(char **position_string, char *str, int *i, int *y)
{
	int x = 0;

	while ((str[*i] >= 'A' && str[*i] <= 'Z') || (str[*i] >= 'a' &&
			str[*i] <= 'z') || (str[*i] >= '0' && str[*i] <= '9') ||
			str[*i] == '/' || str[*i] == '_' ||
			str[*i] == '-' || str[*i] == '.' ||str[*i] == '|') {
		position_string[*y][x] = str[*i];
		x++;
		*i = *i + 1;
	}
	position_string[*y][x] = '\0';
	*y = *y + 1;
	x = 0;
	return (position_string);
}

char **fill_letters2(char **position_string, char *str)
{
	int y = 0;
	int i = 0;

	while (str[i] != '\0') {
		position_string[y] = malloc(sizeof(char) * (my_strlen(str)));
		while (!((str[i] >= 'A' && str[i] <= 'Z') ||
			(str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= '0' && str[i] <= '9') || str[i] == '/' ||
			str[i] == '_' || str[i] == '-' || str[i] == '.'
			|| str[i] == '|')) {
			i++;
			if (str[i] == '\0') {
				position_string[y] = NULL;
				return (position_string);
			}
		}
		position_string = fill_letters3(position_string, str, &i, &y);
	}
	position_string[y] = NULL;
	return (position_string);
}

char **transformread(char *str)
{
	char **position_string;
	int counted_word;

	counted_word = wordcount2(str);
	position_string = malloc(sizeof(char *) * counted_word + 16);
	position_string = fill_letters2(position_string, str);
	return (position_string);
}
