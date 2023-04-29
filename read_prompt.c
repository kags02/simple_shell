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
		if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
	cmd[strlen(cmd) - 1] = '\0';
}
/**
 * print_node - prints a part of sentence which contain a string.
 * @head: pointer to linked list to search in.
 * @h: the string to search for.
 * Return: the pointer to a char excluding string h.
 */
char *print_node(list_t *head, char *h)
{
	unsigned int i = 0;
	char *s;
		while (head != NULL)
	{
		if (lookfor(h, (head)->str) == 0)
		{
			s = addressreturn(h, head->str);
			return (s);
		}
		head = head->next;
		i++;
	}

		return (NULL);
}
/**
 * addressreturn - part of the print_node.
 * @e: the pointer to string.
 * @f: pointer to string.
 * Return: pointer to string.
 */
char *addressreturn(char *e, char *f)
{
	int y = 0;

	while (*e && *f)
	{
		if (f[y] != e[y])
			return (f + y + 1);
		f++;
		e++;
		y++;
	}
	return (NULL);
}

