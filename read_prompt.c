#include "shell.h"

/**
 * read_prompt - read the command from standard input
 * @cmd: array of strings
 */

void read_prompt(char *cmd)
{
	fgets(cmd, MAX_CMD_LEN, stdin);

	if (feof(stdin))
	{
		printf("\n");
		exit(0);
	}
	cmd[strlen(cmd) - 1] = '\0';
}
