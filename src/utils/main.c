/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** PSU_minishell2_2017
*/

#include "my.h"

int main(int ac, char **av, char **env)
{
	list_t list;
	alias_t *alias = initalias();
	int ret = 0;

	if (av != NULL && ac == 1) {
		init_list(&list);
		env_to_list(&list, env);
		ret = prompt(&list, alias);
	}
	return (ret);
}
