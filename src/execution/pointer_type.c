/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** PSU_minishell2_2017
*/

#include "my.h"

static const pointeur_t pointeur_g[] = {
	{"setenv", &my_setenv},
	{"env", &my_env},
	{"exit", &my_exit},
	{"cd", &my_cd},
	{"unsetenv", &my_unsetenv},
	{NULL, NULL}
};

int verif_alias_builtins(char **i, list_t *list, alias_t *alias)
{
	alias_t *tmp = alias->next;
	int j = 0;
	char **i2 = (char **)malloc(sizeof(char *) * 2);
	char *tableau2 = (char *)malloc(sizeof(char) * 2 * 2);
	int count = 0;

	for (int i = 0; i < 2; i++)
		i2[i] = &tableau2[i * 2];
	while (tmp) {
		if (strncmp(tmp->aliascommand, i[0], strlen(i[0])) == 0) {
			i2[0] = strcpy(i2[0], tmp->command);
			i2[1] = NULL;
			pointeur_g[0].pointeur(list, i2);
			count++;
		}
		tmp = tmp->next;
		j++;
	}
	return (count);
}

int find_builtin(list_t *list, char **i, alias_t *alias)
{
	if (!i)
		return (84);
	if (verif_alias_builtins(i, list, alias) != 0)
		return (0);
	for (int x = 0; pointeur_g[x].name != NULL; x++) {
		if (!i[0])
			return (84);
		if (my_strncmp(i[0], pointeur_g[x].name, my_strlen(i[0])) == 0)
		{
			pointeur_g[x].pointeur(list, i);
			return (0);
		}
	}
	return (1);
}
