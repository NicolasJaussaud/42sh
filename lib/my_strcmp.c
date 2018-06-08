/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** strcmp
*/

#include "my.h"

int my_strcmp(const char *obj_cmp_1, const char *obj_cmp_2)
{
	int i = 0;
	int j = 0;

	if (!obj_cmp_1 || !obj_cmp_2)
		return (84);
	for (; obj_cmp_1[i] && obj_cmp_2[j]; i++, j++) {
		if (obj_cmp_1[i] != obj_cmp_2[j])
			return (1);
	}
	return (0);
}
