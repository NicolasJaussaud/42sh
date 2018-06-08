/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** PSU_minishell2_2017
*/

#include "my.h"

bool push_elem(list_t *list, char *data, int pos)
{
	elem_t *new_elem = create_new_elem(data);
	int i = 0;

	if (list->back == NULL && new_elem != NULL)
		push_back(list, data);
	else if (list->front == NULL && new_elem != NULL)
		push_front(list, data);
	else {
		for (elem_t *elem = list->front; elem != NULL
		&& i < pos; elem = elem->next, i++) {
			new_elem->next = elem->next;
			new_elem->prev = elem;
			elem->next = new_elem;
			new_elem->next->prev = new_elem;
			list->size++;
		}
	}
	return (true);
}

bool push_back(list_t *list, char *data)
{
	elem_t *elem = create_new_elem(data);

	if (elem == NULL)
		return (false);
	if (list->back == NULL) {
		list->back = elem;
		list->front = elem;
		list->size++;
	} else {
		list->back->next = elem;
		elem->prev = list->back;
		list->back = elem;
		list->size++;
	}
	return (true);
}

bool push_front(list_t *list, char *data)
{
	elem_t *elem = create_new_elem(data);

	if (elem == NULL)
		return (false);
	if (list->front == NULL) {
		list->back = elem;
		list->front = elem;
		list->size++;
	} else {
		list->front->prev = elem;
		elem->next = list->front;
		list->front = elem;
		list->size++;
	}
	return (true);
}
