/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** echo
*/

#include "my.h"

void my_echo7(char **i)
{
	for (int x = 1; i[x] != NULL; x++) {
		printf("%s", i[x]);
		if (my_strlen_array(i) > 1)
			printf(" ");
	}
	printf("\n");
}

void my_echo6(char **i, list_t *list, int *j, int *x)
{
	char *i_for_env = malloc(sizeof(char) * strlen(i[1]));

	if (strlen(i[1]) == 1)
		printf("%c\n", 36);
	else {
		for (; i[1][*x] != '\0'; *x = *x + 1, *j = *j + 1)
			i_for_env[*j] = i[1][*x];
		i_for_env[*j] = '\0';
		brows_and_find_data(list, i_for_env);
	}
}

char *maj_to_min(char *av)
{
	char *my_new_av = malloc(sizeof(char) * (my_strlen(av) + 1));
	int j = 0;

	for (int i = 0; av[i] != '\0'; i++, j++) {
		if (av[i] >= 'a' && av[i] <= 'z')
			my_new_av[j] = (av[i] - 32);
		else
			my_new_av[j] = av[j];
	}
	my_new_av[j] = '\0';
	return (my_new_av);
}

void brows_and_find_data(list_t *list, char *input)
{
	elem_t *elem = list->front;
	char **array = NULL;
	char *i = maj_to_min(input);
	if (!i)
		exit (84);
	for (int j = 0; elem != NULL; elem = elem->next, j++) {
		if (my_strncmp(i, elem->data, strlen(i)) == 0) {
			array = my_str_to_word_tab(elem->data, '=');
			for (int x = 1; array[x] != NULL; x++)
				printf("%s", array[x]);
			printf("\n");
			return;
		}
	}
	printf("%s", input);
	printf(": Undefined variable.\n");
}