/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** redirection_right
*/

#include "my.h"

char *exec_redir_right2(int tube[2], char *buffer)
{
	int i = 0;
	char buf;

	close(tube[1]);
	for (; read(tube[0], &buf, 1) > 0; i++)
		buffer[i] = buf;
	buffer[i] = '\0';
	close(tube[0]);
	return (buffer);
}

char *exec_redir_right(char **my_input, char *buffer, list_t *list)
{
	int tube[2];
	pid_t pid;
	int status = 0;

	pipe(tube);
	pid = fork();
	if (pid != 0) {
		exec_redir_right2(tube, buffer);
		return (buffer);
	} else {
		close(tube[0]);
		dup2(tube[1], 1);
		if (access(my_input[0], F_OK) == 0) {
			execvp(my_input[0], my_input);
		} else if (access(my_input[0], F_OK) != 0) {
			verify_exec_redir(list, my_input);
		}
		close(tube[1]);
		waitpid(pid, &status, 0);
	}
	return (NULL);
}

void redir_right2(char *buffer, char **apres, FILE *fichier)
{
	if ((fichier = fopen(apres[0], "w+")) == NULL)
		return;
	if (buffer != NULL)
		fprintf(fichier, "%s", buffer);
	fclose(fichier);
}

void redir_right(char *my_input, char **apres, list_t *list)
{
	FILE *fichier = NULL;
	int i = 0;
	char *buffer = malloc(sizeof(char) * 4096);
	char *str = malloc(sizeof(char) * strlen(my_input) + 1);
	char **strtab;

	for (; my_input[i] != '\0'; i++) {
		if (my_input[i] == '<' || my_input[i] == '>')
			break;
		str[i] = my_input[i];
	}
	str[i] = '\0';
	strtab = my_str_to_word_array(str, ' ');
	if (strtab[0] == NULL || apres[0] == NULL)
		return;
	buffer = exec_redir_right(strtab, buffer, list);
	redir_right2(buffer, apres, fichier);
}