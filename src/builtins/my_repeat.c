/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** my_repeat
*/

#include "my.h"

void my_repeat3(list_t *list, alias_t *alias, int nb, char *i)
{
	int j = 0;
	int count = 0;
	char *input = malloc(sizeof(char) * strlen(i));
	int a = 0;

	for (; i[j] != '\0'; j++) {
		if (i[j] >= 48 && i[j] <= 57)
			count++;
		else if (count != 0 && (i[j] < 48 || i[j] > 57))
			break;
	}
	for (; i[j] != '\0'; j++) {
		input[a] = i[j];
		a++;
	}
	input[a] = '\0';
	for (int j = 0; j != nb; j++)
		my_exec(list, input, alias);
}

void my_repeat2(list_t *list, alias_t *alias, char **my_input, char *i)
{
	long int nb = 0;

	if (my_input[1] == NULL || my_input[2] == NULL) {
		printf("repeat: Too few arguments.\n");
		return;
	}
	for (int i = 0; my_input[1][i] != '\0'; i++)
		if ((my_input[1][i] < 48 || my_input[1][i] > 57) &&
			my_input[1][i] != '-') {
			printf("repeat: Badly formed number.\n");
			return;
		}
	nb = atoi(my_input[1]);
	if (nb > 2147483646 || nb < 0)
		return;
	my_repeat3(list, alias, atoi(my_input[1]), i);
}

int my_repeat(list_t *list, alias_t *alias, char *i)
{
	char **my_input = my_str_to_word_array(i, ' ');

	if (my_input[0] == NULL)
		return (0);
	if ((strncmp("repeat", my_input[0], 6) == 0)) {
		my_repeat2(list, alias, my_input, i);
		return (-1);
	}
	return (0);
}