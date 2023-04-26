#include "lists.h"
#include "shell.h"
#include <stdlib.h>
/**
 * free_params - Frees the memory allocated for the param_t structure.
 * 
 * @params: pointer to the param_t structure to free
 *
 * This function frees the dynamically allocated memory used by the param_t
 * structure, including its members: the array of arguments, the environment
 * list, and the input buffer.
 */

void free_params(param_t *params)
{
	unsigned int i;

	if (params->buffer)
		free(params->buffer);
	if (params->nextCommand)
		free(params->nextCommand);
	free_list(params->env_head);
	free_list(params->alias_head);

	for (i = 0; params->args[i]; i++)
		free(params->args[i]);
	free(params->args);
	free(params);
}
