#include "shell.h"
/**
 * listLength - length of list
 * @h: head pointer to list
 *
 * Return: Size of list.
 */
size_t listLength(const singleList *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * toVector - vector of strings	from list
 * @head: pointer to first node
 *
 * Return: Array of strings.
 */

char **toVector(singleList *head)
{
	singleList *node = head;
	size_t i = listLength(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));

	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(sLen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}
		str = scpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
 * printList - displays list
 * @h: pointer to first node
 *
 * Return: Size of list
 */

size_t printList(const singleList *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convertToBase(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * strStartPerfix - finds node with string starting with prefix
 * @node: pointer to list head
 * @prefix: string to check
 * @c: character to check
 *
 * Return: match node or null
 */

singleList *strStartPerfix(singleList *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = _startWith(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * nodeIndex - finds index of node
 * @head: list head
 * @node: pointer to the node
 *
 * Return: -1 or index of node
 */

ssize_t nodeIndex(singleList *head, singleList *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
