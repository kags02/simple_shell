#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARG_LEN 128

int execuve(char *v);
void read_prompt(char *cmd);
void split_prompt(char *cmd, char **args);
void run_prompt(char **args);

#endif
