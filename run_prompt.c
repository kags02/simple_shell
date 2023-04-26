#include "shell.h"

/**
 * run_prompt - execute the prompt
 * @args: pointer to a pointer to the array of strings
 */

void run_prompt(char **args)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			if (args[0] == NULL)
				exit(0);
			perror("Error");
		}
		exit(0);
	} else
	{
		wait(&status);
	}
}
/**
 * execuve - looks for a builtin function and if is not it checks
 *           if the string have '/'.
 * @v: pointer to string.
 * Return: 1 if it is a builtin function or null
 * or when it contains '/' char.
 *         else return 0.
 */
int execuve(char *v)
{
	int y = 0, b;

	b = checkbuiltin(v);
	if (b == 1)
		return (2);
	if (v == NULL)
		return (1);
	while (v[y] != '\0')
	{
		if (v[y] == '/')
		return (1);
		y++;
	}
	return (0);
}
