/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** double_redirection_right
*/

#include "my.h"

void double_redir_right2(char *buffer, FILE *fichier, char **apres)
{
	if ((fichier = fopen(apres[0], "a")) == NULL)
		return;
	if (buffer != NULL)
		fprintf(fichier, "%s", buffer);
	fclose(fichier);
}

void double_redir_right(char *my_input, char **apres, list_t *list)
{
	FILE *fichier = NULL;
	int i = 0;
	char *buffer = malloc(sizeof(char) * 4096);
	char *str = malloc(sizeof(char) * strlen(my_input) + 1);
	char **tabstr;

	for (; my_input[i] != '\0'; i++) {
		if (my_input[i] == '<' || my_input[i] == '>')
			break;
		str[i] = my_input[i];
	}
	str[i] = '\0';
	tabstr = my_str_to_word_array(str, ' ');
	if (tabstr[0] == NULL || apres[0] == NULL)
		return;
	buffer = exec_redir_right(tabstr, buffer, list);
	double_redir_right2(buffer, fichier, apres);
}