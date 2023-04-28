#include "shell.h"

/**
 * main - Entry point
 * @argc: NULL terminated array of strings
 * @argv: number of items in argv
 * Return: 0 if successful
 * @envp: the environment variables.
 */

int main(int argc, char *argv[], char *envp[])
{
	char cmd[MAX_CMD_LEN], df[MAX_CMD_LEN];
	char *args[MAX_ARG_LEN];
	char *e;
	int b, status;
	pid_t pid;
	list_t *head = NULL;

	getcwd(df, MAX_CMD_LEN);
	inputenv(envp, &head);
	if (argc == 1 && argv != NULL)
	{
		while (1)
	{
		prompt();
		read_prompt(cmd);
		split_prompt(cmd, args);
		b = execuve(args[0]);
		if (b == 0)
		{ e = malloc(sizeof(char) * 1024);
			strcpy(e, "/bin/");
			strcat(e, args[0]);
			args[0] = e;
		}
		pid = fork();
		if (pid == 0)
		{
			if (execve(args[0], args, NULL) == -1 && b != 2)
			{
			if (args[0] == NULL)
			exit(0);
			if (b != 2)
				perror(argv[0]);
		}
			else
			exit(0); }
		wait(&status);
			if (args[0] != NULL)
				owncmdhandler(args, envp, &head, df);
			fflush(stdout);	}
	free(e); }
	return (0); }
