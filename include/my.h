/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** my.h
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include "fonc_point.h"
#include "linked_list.h"

#ifndef MY_H
#define MY_H

typedef struct alias_s alias_t;
typedef struct value_s
{
	int ret;
}	value_t;

typedef struct alias_s
{
	char *command;
	char *aliascommand;
	alias_t *next;
}	alias_t;

/*		LIB				*/

int		my_strncmp( const char * s1, const char * s2, size_t n );
char 	**my_str_to_word_tab(char *str, char sep);
void	separate_string(char *i);
int		my_getnbr(char *str);
void	display_char(char c);
void	display_string(char *str);
void	display_array_of_string(char **array);
int		my_strlen(char const *str);
char	**my_str_to_word_array(char const *str, char sep);
int		my_strcmp(const char *obj_cmp_1, const char *obj_cmp_2);
char	*my_strcat(char *str_a, char *str_b);
int		my_strlen_array(char **str);
char	*my_strdup(char *src);
char	*my_strdup(char *src);
char	**str_to_wa(char *str, char f);
char	*clear_string(char *str);
char 	**transformread(char *str);

/*		BUILTINS 		*/

alias_t *initalias(void);
int 	my_alias(alias_t *alias, char *i);
void 	add_node_alias(alias_t *alias, char *command, char *aliascommand);
void 	print_alias(alias_t *alias);
alias_t *suppr_alias_node(alias_t *alias, int count);
void 	unalias(alias_t *alias, char **av);
int 	verif_list_alias(alias_t *alias, char **my_input);
int 	alias_loop(alias_t *alias, char **my_input);
void	cd_null(char **my_env);
void	my_concat(char **my_env, char *new_pwd);
void	call_setenv(list_t *list, char **i);
int 	my_echo(list_t *list, char **i);
char	**get_new_env(char **env);
void	env_to_list(list_t *list, char **env);
char	**list_to_env(list_t *list);
int		my_setenv(list_t *list, char **i);
char	**find_path(list_t *list);
int		my_unsetenv(list_t *list, char **i);
int		my_env(list_t *list, char **i);
int		my_cd(list_t *list, char **i);
int		my_exit(list_t *list, char **i);
int 	my_repeat(list_t *list, alias_t *alias, char *i);
int 	my_foreach(char *i);
int 	my_which(list_t *list, alias_t *alias, char *i);
int 	which_builtins(char *my_input);
int 	which_alias(alias_t *alias, char *my_input);
int 	my_where(list_t *list, alias_t *alias, char *i);
int 	where_builtins(char *my_input);
int 	where_alias(alias_t *alias, char *my_input);
void	brows_and_find_data(list_t *list, char *input);
char 	*maj_to_min(char *av);
void  	my_echo6(char **i, list_t *list, int *j, int *x);
void 	my_echo7(char **i);

/*		EXECUTION 		*/

int 	my_pipe(char *my_input, alias_t *alias, list_t *list);
int		verify_exec(list_t *list, char **my_input);
// void parse_and_fill_tree(tree_t *tr, char *i);
int		my_exec(list_t *list, char *i, alias_t *alias);
int		find_builtin(list_t *list, char **i, alias_t *alias);
int		my_fork(list_t *list, char **my_input);
void	my_count(int count, char **my_input);
void 	redir_right(char *my_input, char **apres, list_t *list);
int 	verify_exec_redir(list_t *list, char **my_input);
void 	double_redir_right(char *my_input, char **apres, list_t *list);
void 	redir_left(char *my_input, char **apres, list_t *list);
char 	*exec_redir_right(char **my_input, char *buffer, list_t *list);
int 	verify_exec_redir(list_t *list, char **my_input);
char *initap(char *ap, int count, char **tab);
char *initav(char *av, int count, char **tab);
char *my_strcat1(char *dest, char *src);

/*		LIST 			*/

/*		PARSEUR 		*/

int 	parseur(list_t *list, alias_t *alias, char *i);
char 	**cut_stringap(char *my_input, int nb);

/*		UTILS 			*/

int 	prompt(list_t *list, alias_t *alias);
void 	check_signal(void);

#endif