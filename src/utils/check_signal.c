/*
** EPITECH PROJECT, 2018
** checksignal
** File description:
** checksignal
*/

#include "my.h"

static void sig_handler(int sig){
	(void)sig;
	exit(1);
}

void check_signal(void)
{
	if (signal(SIGINT, sig_handler) == SIG_ERR) {
		perror("error.");
		exit (1);
	}
	if (signal(SIGPIPE, sig_handler) == SIG_ERR) {
		perror("error.");
		exit (1);
	}
	if (signal(SIGSEGV, sig_handler) == SIG_ERR) {
		perror("error.");
		exit (1);
	}
	if (signal(SIGSYS, sig_handler) == SIG_ERR) {
		perror("error.");
		exit (1);
	}
	if (signal(SIGBUS, sig_handler) == SIG_ERR) {
		perror("error.");
		exit (1);
	}
}