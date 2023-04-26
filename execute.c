#include "shell.h"
/**
 * print_list - prints all elements of linked list.
 * @h: the linked list to print.
 * Return: the last node
 */
size_t print_list(const list_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("%s\n", h->str);
		nodes++;
		h = h->next;
	}
	return (nodes);
}
/**
 * insert_nodeint_at_index - insert node at given index.
 * @head: the list to insert.
 * @idx: at which we insert.
 * @h: the string to insert.
 * Return: the updated list.
 */
list_t *insert_nodeint_at_index(list_t **head, int idx, const char *h)
{
	list_t *new_node = NULL;
	list_t *previous_node = NULL;
	int i = 0;
	size_t v = idx;
	char *std;

	std = strdup(h);
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL || v > listint_len(*head))
	{
		free(new_node);
		return (NULL);
	}
	new_node->str = std;
	new_node->next = NULL;
	while (head != NULL)
	{
		if (i == idx)
		{
			if (i == 0)
			{
				new_node->next = *head;
				*head = new_node;
				return (new_node);
			}
			new_node->next = previous_node->next;
			previous_node->next = new_node;
			return (new_node);
		}
		else if ((i + 1) == idx)
			previous_node = *head;
		head = &((*head)->next);
		i++;
	}
	return (NULL);
}
/**
 *  insertdelete - this updates pwd after changing directory.
 *  @head: the linked list to update.
 *  Return: void.
 */
void insertdelete(list_t **head)
{
	int i, j, y;
	char c[1024];

	char p[1024] = {'P', 'W', 'D', '='};

	getcwd(c, 1024);
	i = delete_node(head, "PWD");
	for (j = 0; p[j] != '\0'; j++)
		;
	for (y = 0; c[y] != '\0'; y++)
	{
		p[j] = c[y];
		j++;
	}
	p[j] = '\0';
	insert_nodeint_at_index(head, i, p);
}
/**
 * checkbuiltin - checks if the input is built in.
 * @v: the pointer to input string.
 * Return: 0.
 */
int checkbuiltin(char *v)
{
	int b = 5, i;

	char *d[]  = {"exit", "cd", "env", "setenv", "unsetenv"};

	if (v == NULL)
		return (0);
	for (i = 0; i < b; i++)
	{
		if (strcmp(v, d[i]) == 0)
			return (1);
	}
	return (0);
}
#include "shell.h"
/**
 * owncmdhandler - look for the builtin and execute.
 * @parsed: pointer to arrays of strings.
 * @envp: the environment variables.
 * @head: pointer to pointer of linked list.
 * @s: contain the previous directory.
 * Return: 1 if built in function is found and 0 if none.
 */
int owncmdhandler(char **parsed, char **envp, list_t **head, char *s)
{
	int b = 5, i, c;
	char f[1024], w[1024], *t, *d[] = {"exit", "cd", "env", "setenv", "unsetenv"};

	for (i = 0; i < b; i++)
	{
		if (strcmp(parsed[0], d[i]) == 0)
		{c = i + 1;
			break; }}
	switch (c)
	{
		case 1:
			_functionexit(parsed[1]);
			return (1);
		case 2:
			if (strcmp(parsed[0], "cd") == 0)
			{getcwd(w, 1024);
				b = chdir(parsed[1]);
				if (b == -1)
				{
					if (parsed[1] == NULL && envp != NULL)
					{ t = print_node(*head, "HOME");
							chdir(t); }
					else if (strcmp(parsed[1], "-") == 0)
						chdir(s); }
				strcpy(s, w);
				insertdelete(head); }
				return (1);
		case 3:
			if (c == 3)
			{ print_list(*head);
				return (1); }
			return (1);
		case 4:
			hello(f, head, parsed, c);
			return (1);
		case 5:
			return (1);
		default:
			break; }
	return (0); }
