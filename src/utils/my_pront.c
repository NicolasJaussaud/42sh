/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** my_pront
*/

#include "my.h"

void display_prompt(char tampon[4096])
{
	if (getcwd(tampon, 4096) == NULL)
		exit(84);
	display_string(tampon);
	display_string(" ~$ ");
}

int *initflux(int flux[2])
{
	flux[0] = dup(0);
	flux[1] = dup(1);
	return (flux);
}

int *prompt2(int flux[2])
{
	check_signal();
	dup2(flux[0], 0);
	dup2(flux[1], 1);
	return (flux);
}

int prompt(list_t *list, alias_t *alias)
{
	int  characters = 1;
	char *i = NULL;
	size_t bufsize = 0;
	char tampon[4096];
	static int ret = 0;
	int *flux = malloc(sizeof(int) * 2);

	flux = initflux(flux);
	while (characters != 0) {
		if (isatty(0))
			display_prompt(tampon);
		if ((characters = getline(&i, &bufsize, stdin)) == -1)
			return (ret);
		check_signal();
		ret = parseur(list, alias, i);
		flux = prompt2(flux);
	}
	free(i);
	free(flux);
	return (ret);
}