/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** echo
*/

#include "my.h"

int my_echo5(char **i, char c)
{
	if (my_strncmp(i[1], "-n", 2) == 0 && i[2] != NULL
	&& i[2][0] != c) {
		for (int x = 1; i[x] != NULL; x++) {
			printf("%s", i[x]);
			if (my_strlen_array(i) > 1)
				printf(" ");
		}
		return (0);
	}
	if (i[1] != NULL && i[1][0] != c) {
		my_echo7(i);
		return (0);
	}
	return (0);
}

void my_echo4(char **i, int *j, int *x, list_t *list)
{
	char *i_for_env = malloc(sizeof(char) * strlen(i[2]));

	if (strlen(i[2]) == 1)
		printf("%c", 36);
	else {
		for (; i[2][*x] != '\0'; *x = *x + 1, *j = *j + 1)
			i_for_env[*j] = i[2][*x];
		i_for_env[*j] = '\0';
		brows_and_find_data(list, i_for_env);
	}
}

int my_echo3(list_t *list, char **i, int *j, int *x)
{
	if (my_strncmp(i[1], "-n", 2) == 0 && i[2] == NULL)
		return (1);
	else if (my_strncmp(i[1], "-n", 2) == 0 && i[2] != NULL
	&& i[2][0] == 36) {
		my_echo4(i, j, x, list);
		return (1);
	}
	return (0);
}

int my_echo2(list_t *list, char **i, int *j, int *x)
{
	if (i[1] == NULL) {
		printf("\n");
		return (1);
	}
	if (i[1] != NULL && i[1][0] == 36) {
		my_echo6(i, list, j, x);
		return (1);
	}
	return (0);
}

int my_echo(list_t *list, char **i)
{
	char c = 36;
	int j = 0;
	int x = 1;
	int ret = 0;

	if (i[1] == NULL)
		return (1);
	else if ((my_echo3(list, i, &j, &x)) == 1)
		return (0);
	if ((my_echo2(list, i, &j, &x)) == 1)
		return (0);
	ret = my_echo5(i, c);
	return (ret);
}
