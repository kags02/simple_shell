#include "shell.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */
int _atoi(char *s)
{
	int i, d, n, len, f, digit;

	i = 0;
	d = 0;
	n = 0;
	len = 0;
	f = 0;
	digit = 0;

	while (s[len] != '\0')
		len++;

	while (i < len && f == 0)
	{
		if (s[i] == '-')
			++d;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}

	if (f == 0)
		return (0);

	return (n);
}
/**
 * add_node_end - add node at the end of the linked list.
 * @head: the pointer to list_t.
 * @str: the string to add at the end of the linked list.
 * Return: the new linked list.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	char *dup;
	list_t *new, *last;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	dup = strdup(str);
	if (str == NULL)
	{
		free(new);
		return (NULL);
	}
	new->str = dup;
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	return (*head);
}
/**
 * lookfor - looks if a word is contained in a phrase.
 * @h : the word to check.
 * @p : the phrase to check in.
 * Return: 1 if not contained and 0 otherwise.
 */
int lookfor(char *h, char *p)
{
	int y = 0;

	while (h[y] != '\0' && p[y] != '\0')
	{
		if (h[y] != p[y])
			return (1);
		y++;
	}
	return (0);
}
/**
 * delete_node - delete node which contain specified string.
 * @head: the linked list pointer.
 * @h: the pointer to string to search for.
 * Return: the nth node where the string was located otherwise -1.
 */
int delete_node(list_t **head, char *h)
{
	list_t *old_node = NULL;
	list_t *previous_node = NULL;
	unsigned int i = 0, list_len = listint_len(*head);

	while (head != NULL)
	{
		if (lookfor(h, (*head)->str) == 0)
		{
			old_node = *head;
			if (i == 0)
			{
				*head = old_node->next;
				free(old_node);
				return (i);
			}
			previous_node->next = old_node->next;
			free(old_node);
			return (i);
		}
		previous_node = *head;
		head = &((*head)->next);
		i++;
		if (i == list_len)
			return (-1);
	}
	return (-1);
}
/**
 * listint_len - list the nodes of the linked list.
 * @h: the pointer to linked list.
 * Return: the number of nodes of linked list.
 */
size_t listint_len(const list_t *h)
{
	const list_t *cursor = h;
	size_t count = 0;

	while (cursor != NULL)
	{
		count += 1;
		cursor = cursor->next;
	}
	return (count);
}
