/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** PSU_minishell2_2017
*/

#include "my.h"

int my_unsetenv(list_t *list, char **i)
{
	char **tab = NULL;
	elem_t *elem = list->front;
	int x = 0;

	if (!i[1]) {
		display_string("unsetenv: Too few arguments.\n");
		return (1);
	} else {
		for (; elem != NULL; x++) {
			tab = my_str_to_word_array(elem->data, '=');
			if (my_strcmp(tab[0], i[1]) == 0)
				pop_back(list);
			elem = elem->next;
		}
	}
	for (int j = 0; tab[j] != NULL; j++)
		free(tab[j]);
	free(tab);
	return (0);
}

int my_env(list_t *list, char **i)
{
	(void)i;
	elem_t *elem = NULL;
	int x = 0;

	for (elem = list->front; elem != NULL; x++) {
		display_string(elem->data);
		display_char('\n');
		elem = elem->next;
	}
	return (0);
}

int my_exit(list_t *list, char **i)
{
	(void)list;
	int status = my_getnbr(i[1]);

	if (my_strlen_array(i) > 2) {
		display_string("exit: Expression Syntax\n");
		exit(1);
	}
	if (my_strlen_array(i) == 2)
		exit(status);
	if (my_strlen_array(i) == 1)
		exit(0);
	return (0);
}
