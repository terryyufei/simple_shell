#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
#include "shell.h"
#include "main.h"

/**
 * list_len - the number of elements in a linked list_t list.
 * @h: start of list
 *
 * Return: length of list
 */
size_t list_len(list_t *h)
{
	size_t i;

	for (i = 0; h != 0; i++)
		h = h->next;
	return (i);
}

/**
 * print_list - prints all the elements of a list_t list.
 * @h: start of list
 *
 * Return: length of list
 */
size_t print_list(list_t *h)
{
	int count;

	for (count = 0; h != 0; count++)
	{
		if (h->str == NULL)
			break;
		_printf("%s\n", h->str);
		h = h->next;
	}
	return (count);
}

/**
 * add_node - adds a new node at the beginning of a list_t list.
 * @head: start of list
 * @str: key
 * @val: value
 * Return: ptr to new head
 */
list_t *add_node(list_t **head, char *str, char *val)
{
	list_t *new;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = _strdup(str);
	new->len = _strlen(new->str);
	new->val = _strdup(val);
	new->valLen = _strlen(val);
	new->next = *head;
	*head = new;

	return (new);
}

/**
 * get_node - search for a node
 * @head: start of list
 * @str: key
 * Return: ptr to desired node, NULL if not found
 */
list_t *get_node(list_t *head, char *str)
{
	list_t *h;

	if (!head)
		return (NULL);
	h = head;
	while (h)
	{
		if (!_strcmp(h->str, str))
			break;
		h = h->next;
	}
	return (h);
}

/**
 * free_list - clears a linked list from mem
 * @head: ptr to head of linked list
 */
void free_list(list_t *head)
{
	list_t *ptr = head;

	while (head)
	{
		ptr = head->next;
		free(head->str);
		free(head->val);
		free(head);
		head = ptr;
	}
}
