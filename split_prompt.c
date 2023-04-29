#include "shell.h"

/**
 * split_prompt - split the command into arguments using space aa a delimiter
 * @cmd: pointer to the cmd
 * @args: pointer to a pointer of the arguments
 */

void split_prompt(char *cmd, char **args)
{
	int i;

	args[0] = strtok(cmd, " ");
	i = 0;

	while (args[i] != NULL)
	{
		i++;
		args[i] = strtok(NULL, " ");
	}
}
