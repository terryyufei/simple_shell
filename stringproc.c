#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include <stdio.h>
/**
 * process_string - process the next command into string tokens
 * @params: parameters
 *
 * Return: number of tokens
 */
int process_string(param_t *params)
{
	char *token = NULL, *state = NULL;
	char *alias = NULL, *state_2 = NULL, *val;
	list_t *node;

	token = _strtok(params->nextCommand, " \n\t", &state);
	if (!token)
	{
		params->tokCount = 0;
		return (0);
	}
	node = get_node(params->alias_head, token);
	if (node != NULL)
	{
		free(token);
		token = NULL;
		alias = _strdup(node->val);
		if (!alias)
		{
			write(STDERR_FILENO,
			      "alias expansion malloc error\n", 18);
			free_params(params);
			exit(-1);
		}
		val = _strtok(alias, " \n\t", &state_2);
		(params->args)[(params->tokCount)++] = val;
		while (val)
		{
			val = _strtok(alias, " ", &state_2);
			(params->args)[(params->tokCount)++] = val;
		}
		free(alias);
	}
	else
		(params->args)[(params->tokCount)++] = token;
	token = _strtok(params->nextCommand, " \n\t", &state);
	params->args[params->tokCount++] = token;
	while (token)
	{
		token = _strtok(params->nextCommand, " \n\t", &state);
		(params->args)[(params->tokCount)++] = token;
		if (params->tokCount == params->argsCap)
		{
			params->argsCap += 10;
			params->args = _realloc(params->args,
						params->argsCap - 10,
						params->argsCap);
			if (!(params->args))
			{
				write(STDERR_FILENO, "realloc error\n", 14);
				free_params(params);
				exit(-1);
			}
		}
	}
	return (params->tokCount - 1);
}
