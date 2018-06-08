/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** linked_list.h
*/

#include <stdlib.h>
#include <stdbool.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct list_elem
{
	char	*data;
	struct list_elem *prev;
	struct list_elem *next;
}		elem_t;

typedef struct list_s
{
	elem_t *front;
	elem_t *back;
	size_t size;
}	list_t;

elem_t *create_new_elem(char *data);
void init_list(list_t *list);
bool push_front(list_t *list, char *data);
bool push_back(list_t *list, char *data);
void pop_front(list_t *list);
void pop_back(list_t *list);
int my_strlen_for_list(list_t *list);
void pop_elem(list_t *list, elem_t *elem);
bool push_elem(list_t *list, char *data, int pos);

#endif
