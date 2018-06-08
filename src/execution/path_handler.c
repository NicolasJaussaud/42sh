/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** minishell2
*/

#include "my.h"

char **find_path(list_t *list)
{
	char **stoc_env = list_to_env(list);
	char **stoc_path = NULL;
	char *path = NULL;
	int i = 0;

	if (!stoc_env)
		return (NULL);
	for (; stoc_env[i] != NULL; i++) {
		if (my_strncmp(stoc_env[i], "PATH=", 5) == 0)
			path = my_strdup(stoc_env[i]);
	}
	stoc_path = my_str_to_word_array(path, ':');
	free (path);
	free (stoc_env);
	return (stoc_path);
}
