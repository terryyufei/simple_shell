#include "main.h"
#include "lists.h"
#include "shell.h"
#include <stdlib.h>

/**
 * _getenv - Gets the value of an environment variable.
 * @name: The name of the environment variable to retrieve.
 * @params: Pointer to the parameter structure containing the environment list.
 *
 * Return: A pointer to the value of the environment variable, or NULL if not.
 *
 * This function searches for an environment variable with the givn name in the
 * linked list of environment variables contained in the parameter structure.
 * If a match is found, the value associated with that variable is duplicated n
 * returned as a string. If no match is found, the function returns NULL.
 */

char *_getenv(char *name, param_t *params)
{
	list_t *ptr = params->env_head;

	while (ptr)
	{
		if (!_strcmp(name, ptr->str))
			return (_strdup(ptr->val));
		ptr = ptr->next;
	}
	return (NULL);
}
