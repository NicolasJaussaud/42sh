/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** PSU_minishell2_2017
*/

#include "my.h"

int my_strlen_for_list(list_t *list)
{
	size_t n = 0;
	elem_t *elem = list->front;

	while (elem != NULL) {
		n++;
		elem = elem->next;
	}
	return (n);
}
