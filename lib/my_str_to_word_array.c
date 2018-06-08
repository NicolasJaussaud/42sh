/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include "my.h"

int wordcount(char const *str, char sep)
{
	int word = 0;
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] == sep || str[i] == '\n' ||
			str[i] == '=' || str[i] == '\t')
			word++;
		i++;
	}
	return (word);
}

char **fill_letters(char **position_string, char const *str, char sep, int y)
{
	int i = 0;

	for (int x = 0; str[i] != '\0'; y++) {
		position_string[y] = malloc(sizeof(char) * strlen(str) + 1);
		for (; str[i] == sep || str[i] == '\n' || str[i] == '='
			|| str[i] == '\t';) {
			i++;
			if (str[i] == '\0') {
				position_string[y] = NULL;
				return (position_string);
			}
		}
		for (; str[i] && str[i] != sep && str[i] != '=' &&
			str[i] != '\n' && str[i] != '\t'; i++, x++)
			position_string[y][x] = str[i];
		position_string[y][x] = '\0';
		x = 0;
	}
	position_string[y] = NULL;
	return (position_string);
}

char **my_str_to_word_array(char const *str, char sep)
{
	char **position_string;
	int counted_word;

	counted_word = wordcount(str, sep);
	position_string = malloc(sizeof(char *) * (counted_word + 2));
	position_string = fill_letters(position_string, str, sep, 0);
	return (position_string);
}
