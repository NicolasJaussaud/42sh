/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** minishell2
*/

#include "linked_list.h"

#ifndef FONC_POINT_H
#define FONC_POINT_H

typedef struct pointeur_s
{
	char *name;
	int (*pointeur)(list_t *, char **);
}	pointeur_t;

typedef struct echo_s
{
	char *name;
	int (*type)(list_t *, char **);
}	echo_t;

#endif
