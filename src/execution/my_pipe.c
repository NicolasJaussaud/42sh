/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** pipe
*/

#include "my.h"

int initpipe(char **tab)
{
	int count = 0;

	if (tab == NULL)
		return (-1);
	for (int i = 0; tab[i] != NULL; i++)
		if (strncmp(tab[i], "|", strlen(tab[i])) == 0) {
			count = i;
			break;
		}
	return (count);
}

void my_pipe4(alias_t *alias, list_t *list, char *ap, char **tab_2)
{
	if (my_alias(alias, ap) == 0 &&
	my_repeat(list, alias, ap) == 0 && my_foreach(ap) == 0
	&& my_which(list, alias, ap) == 0)
		if (find_builtin(list, tab_2, alias) != 0 ||
			strncmp(ap, "exit", 4) == 0)
			execvp(tab_2[0], tab_2);
}

void my_pipe3(alias_t *alias, list_t *list, char *av, char **tab_1)
{
	if (my_alias(alias, av) == 0 &&
		my_repeat(list, alias, av) == 0 && my_foreach(av) == 0 &&
		my_which(list, alias, av) == 0)
		if (find_builtin(list, tab_1, alias) != 0 ||
			strncmp(av, "exit", 4) == 0)
			execvp(tab_1[0], tab_1);
}

void my_pipe2(alias_t *alias, list_t *list, char *av, char *ap)
{
	char **tab_1 = NULL;
	char **tab_2 = NULL;
	int status = 0;
	int link[2];

	tab_1 = my_str_to_word_array(av, ' ');
	tab_2 = my_str_to_word_array(ap, ' ');
	pipe(link);
	int fk = fork();
	if (fk == 0) {
		close(link[0]);
		dup2(link[1], 1);
		my_pipe3(alias, list, av, tab_1);
	} else {
		if (fork() == 0) {
			close(link[1]);
			dup2(link[0], 0);
			my_pipe4(alias, list, ap, tab_2);
		}
		waitpid(fk, &status, 0);
	}
}

int my_pipe(char *my_input, alias_t *alias, list_t *list)
{
	char **tab = NULL;
	char *av = malloc(sizeof(char) * 100);
	char *ap = malloc(sizeof(char) * 100);
	int count = 0;

	av[0] = '\0';
	ap[0] = '\0';
	tab = transformread(my_input);
	if ((count = initpipe(tab)) == -1)
		return (1);
	av = initav(av, count, tab);
	ap = initap(ap, count, tab);
	my_pipe2(alias, list, av, ap);
	return (0);
}