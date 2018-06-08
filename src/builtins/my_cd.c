/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** PSU_minishell2_2017
*/

#include "my.h"

void cd_null(char **my_env)
{
	char *my_char_home = NULL;
	int ls = 0;

	for (; my_env[ls] != NULL; ls++) {
		if (my_strncmp(my_env[ls], "HOME=", 5) == 0) {
			my_char_home = my_strdup(my_env[ls]);
			chdir(my_char_home + 5);
			free(my_char_home);
			break;
		}
	}
}

void my_concat(char **my_env, char *new_pwd)
{
	char *buf = malloc(sizeof(char) * 1024);
	char *old_pwd = getcwd(buf, 1024);
	char *concat_old_pwd = my_strcat("OLDPWD=", old_pwd);
	char *concat_new_pwd = NULL;
	int x = 0;

	concat_new_pwd = my_strcat("PWD=", new_pwd);
	for (; my_env[x] != NULL; x++) {
		if (my_strncmp(concat_old_pwd, "OLDPWD=", 7) == 0)
		my_env[x] = concat_old_pwd;
		if (my_strncmp(concat_new_pwd, "PWD=", 4) == 0)
		my_env[x] = concat_new_pwd;
	}
	free(buf);
}

int my_cd3(char **i)
{
	if (chdir(i[1]) == -1) {
		for (int j = 0; i[1][j] != '\0'; j++)
			if (i[1][j] == '/' && j != 0) {
				printf("%s: Not a directory.\n", i[1]);
				return (-1);
			}
		printf("%s: No such file or directory.\n", i[1]);
		return (-1);
	}
	return (0);
}

void my_cd2(char *new_pwd, char *buf, char **my_env)
{
	new_pwd = getcwd(buf, 1024);
	my_concat(my_env, new_pwd);
	free (buf);
}

int my_cd(list_t *list, char **i)
{
	char **my_env = list_to_env(list);
	char *buf = malloc(sizeof(char) * 1024);
	char *new_pwd = NULL;

	if (!i[1]) {
		cd_null(my_env);
		return (0);
	} else {
		if (my_cd3(i) == -1)
			return (1);
	}
	my_cd2(new_pwd, buf, my_env);
	return (0);
}