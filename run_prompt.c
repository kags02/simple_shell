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
				write(1,"\n",1);
			else
			perror("Error");
		}
		exit(0);
	} else
	{
		wait(&status);
	}
}
int execuve(char *v)
{
	int y=0;
	if (v == NULL)
		return 1;
	while(v[y] != '\0')
	{
		if (v[y] == '/')
		return 1;
		y++;
	}
	return 0;
}
