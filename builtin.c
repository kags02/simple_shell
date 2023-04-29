#include "shell.h"
/**
 * _functionexit - execute the exit function.
 * @s: pointer to char.
 * Return: 1.
 */
int _functionexit(char *s)
{
	if (!s)
	{
		free(s);
		exit(0);
	}
	if (s == NULL)
	{
		free(s);
		exit(0);
	}
	if (_atoi(s) != -1)
	{	
		free(s);
	exit(_atoi(s)); }
	return (1);
}
/**
 * hello - add variable to other variables.
 * @f: the array to store the variable.
 * @head: the linked list which contain environment variable.
 * @parsed: the input from the user.
 * @c: the integer.
 */
void hello(char *f, list_t **head, char **parsed, int c)
{
	if (parsed[1] != NULL && parsed[2] != NULL)
	{
		strcpy(f, parsed[1]);
strcat(f, "=");
strcat(f, parsed[2]);
add_node_end(head, f);
	}
	else if (parsed[1] == NULL && c == 4)
	{
		print_list(*head);
	}
}
/**
 * inputenv - puts environment variables in linked list.
 * @envp: pointer to environment variables.
 * @head: pointer to linked list.
 * Return: nothing.
 */
void inputenv(char **envp, list_t **head)
{
	int e = 0;

	while (envp[e] != NULL)
	{
		add_node_end(head, envp[e]);
		e++;
	}
}
/**
 * prompt - prints where to put command.
 * Return: void.
 */
void prompt(void)
{
	char *prompt = {"$ "};

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, prompt, strlen(prompt));
	}
}

