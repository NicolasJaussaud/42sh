/*
** EPITECH PROJECT, 2018
** epitech
** File description:
** minishell2
*/

#include "my.h"

int my_fork(list_t *list, char **my_input)
{
	value_t all;
	char **my_env = list_to_env(list);
	int my_fork = fork();
	int status = 0;

	if (my_fork == 0) {
		execve(my_input[0], my_input, my_env);
	} else if (my_fork == 11) {
		all.ret = 139;
	} else {
		waitpid(my_fork, &status, 0);
		return (status);
	}
	free (my_env);
	return (all.ret);
}

void my_count(int count, char **my_input)
{
	if (my_input != NULL) {
		if (count == 0) {
			display_string(my_input[0]);
			display_string(": Command not found.\n");
		}
	}
}

int verify_exec(list_t *list, char **my_input)
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
				my_fork(list, my_input);
				break;
			}
		}
		my_count(count, &my_exc);
		free (my_path);
		return (0);
	} else
		return (84);
}

int my_exec(list_t *list, char *i, alias_t *alias)
{
	int ret = 0;
	char **my_input = my_str_to_word_array(i, ' ');

	if (my_input[0] != 0) {
		if ((ret = find_builtin(list, my_input, alias)) == 0)
			return (ret);
		if (access(my_input[0], F_OK) == 0) {
			my_fork(list, my_input);
		} else if (access(my_input[0], F_OK) != 0) {
			verify_exec(list, my_input);
		}
		free (my_input);
		return (0);
	} else
		return (ret);
	return (ret);
}