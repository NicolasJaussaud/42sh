/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** PSU_minishell2_2017
*/


#include "my.h"

char **get_new_env(char **env)
{
	char **new_env = malloc(sizeof(char *) * (my_strlen_array(env) + 1));
	int i = 0;

	if (env != NULL) {
		for (; env[i] != NULL; i++)
			new_env[i] = my_strdup(env[i]);
	}
	new_env[i] = NULL;
	return (new_env);
}

void env_to_list(list_t *list, char **env)
{
	char **list_of_env = get_new_env(env);
	int i = 0;

	for (; list_of_env[i] != NULL; i++)
		push_back(list, list_of_env[i]);
	free (list_of_env);
}

char **list_to_env(list_t *list)
{
	elem_t *elem = list->front;
	char **env_ls = malloc(sizeof(char *) * (my_strlen_for_list(list) + 1));
	int i = 0;

	for (; elem != NULL; elem = elem->next, i++) {
		env_ls[i] = elem->data;
	}
	env_ls[i] = NULL;
	free(elem);
	return (env_ls);
}
