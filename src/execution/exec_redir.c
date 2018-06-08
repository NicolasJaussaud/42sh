/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** exec_redir
*/

#include "my.h"

int verify_exec_redir(list_t *list, char **my_input)
{
	char **my_path = find_path(list);
	char *a;
	char *my_exc = my_input[0];
	int x = 0;
	int count = 0;

	if (my_input != NULL) {
		a = my_strcat("/", my_input[0]);
		for (x = 0; my_path[x] != NULL; x++) {
			my_input[0] = my_strcat(my_path[x], a);
			if (access(my_input[0], F_OK) == 0) {
				count++;
				execvp(my_input[0], my_input);
				break;
			}
		}
		my_count(count, &my_exc);
		free (my_path);
		return (0);
	} else
		return (84);
}