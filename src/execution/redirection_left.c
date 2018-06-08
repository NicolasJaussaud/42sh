/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** redirection_left
*/

#include "my.h"

void redir_left_exec2(int tube[2], char **file, list_t *list, char **my_input)
{
	if ((tube[0] = open(file[0], O_RDONLY)) == -1)
		return;
	dup2(tube[0], 0);
	if (access(my_input[0], F_OK) == 0)
		execvp(my_input[0], my_input);
	else if (access(my_input[0], F_OK) != 0)
		verify_exec_redir(list, my_input);
	close(tube[0]);
	close(tube[1]);
}

void redir_left_exec(char **my_input, char **file, list_t *list)
{
	int tube[2];
	pid_t pid;
	int status = 0;

	if (pipe(tube) == -1)
		return;
	if ((pid = fork()) == -1)
		return;
	if (pid != 0) {
		close(tube[1]);
		close(tube[0]);
		waitpid(pid, &status, 0);
	} else {
		redir_left_exec2(tube, file, list, my_input);
	}
}

void redir_left(char *my_input, char **apres, list_t *list)
{
	char *str = malloc(sizeof(char) * strlen(my_input) + 1);
	char **tabstr;
	int i = 0;

	for (; my_input[i] != '\0'; i++) {
		if (my_input[i] == '<' || my_input[i] == '>')
			break;
		str[i] = my_input[i];
	}
	str[i] = '\0';
	tabstr = my_str_to_word_array(str, ' ');
	if (tabstr[0] == NULL || apres[0] == NULL)
		return;
	redir_left_exec(tabstr, apres, list);
}