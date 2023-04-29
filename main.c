#include "shell.h"

/**
 * main - Entry point
 * @argc: NULL terminated array of strings
 * @argv: number of items in argv
 * Return: 0 if successful
 */

int main()
{
	char cmd[MAX_CMD_LEN];
	char *args[MAX_ARG_LEN];
	char *f,*e;
	int b;

	while (1)
	{
		printf("$ ");
		read_prompt(cmd);
		split_prompt(cmd, args);
		f = args[0];
		b = execuve(f);
		if (b == 0)
		{
			e = malloc(sizeof(char)*1024);
		        strcpy(e, "/bin/");
		         strcat(e, f);
		        args[0] = e;
		}
		run_prompt(args);
	}
	free(e);
	return (0);
}
