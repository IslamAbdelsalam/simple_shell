#include "shell.h"

/**
 * addNodeAtBegain - sets a node at the beginning of the list
 * @head: list head
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
singleList *addNodeAtBegain(singleList **head, const char *str, int num)
{
	singleList *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(singleList));
	if (!new_head)
		return (NULL);
	memory_set((void *)new_head, 0, sizeof(singleList));
	new_head->num = num;
	if (str)
	{
		new_head->str = sDup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * addNodeToTail - sets a node at the end of the list
 * @head: list head
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
singleList *addNodeToTail(singleList **head, const char *str, int num)
{
	singleList *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(singleList));
	if (!new_node)
		return (NULL);
	memory_set((void *)new_node, 0, sizeof(singleList));
	new_node->num = num;
	if (str)
	{
		new_node->str = sDup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * strNodeContent - prints all nodes in a list
 * @h: pointer to the head node
 *
 * Return: size of list
 */
size_t strNodeContent(const singleList *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * deleteNode - delete node at index
 * @head: pointer to the head node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int deleteNode(singleList **head, unsigned int index)
{
	singleList *node, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - frees all nodes of a list
 * @head_ptr: head pointer
 *
 * Return: void
 */
void free_list(singleList **head_ptr)
{
	singleList *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}

