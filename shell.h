#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARG_LEN 128
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;
void inputenv(char** envp, list_t **head);
list_t *insert_nodeint_at_index(list_t **head, unsigned int idx, const char *h);
list_t *add_node_end(list_t **head, const char *str);
int lookfor(char *h, char *p);
int delete_node(list_t **head, char *h);
size_t listint_len(const list_t *h);
size_t print_list(const list_t *h);
void insertdelete( list_t **head);
char *mystrtok(char* str, char *comp);
int checkbuiltin(char *v);
int owncmdhandler(char **parsed, char **envp, list_t **head, char *s );
int execuve(char *v);
void read_prompt(char *cmd);
void split_prompt(char *cmd, char **args);
void run_prompt(char **args);
void _printvar(char **envp);
char* string_token(char *str, char *delimiter);
int _atoi(char *s);
char *print_node(list_t *head, char *h);
char *addressreturn(char *e, char *f);
int _functionexit(char *s);
void hello(char *f, list_t **head, char **parsed, int c);
#endif
