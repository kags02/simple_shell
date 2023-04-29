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
/**
* free_listint2 - frees a linked list.
*@head: head of a list.
*
*Return: no return.
*/
 void free_listint2(list_t **head)
{
list_t *temp;
list_t *curr;
if (head != NULL)
{
curr = *head;
while ((temp = curr) != NULL)
{
curr = curr->next;
free(temp);
}
*head = NULL;
}
}

