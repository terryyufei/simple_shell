#include <stdlib.h>
#include <limits.h>
#include "shell.h"
#include "main.h"
/**
 * validNum - check if string is a valid number
 * @s: string
 *
 * Return: 0 if false, 1 otherwise
 */
int validNum(char *s)
{
	while (*s)
	{
		if (*s > '9' || *s < '0')
			return (0);
		s++;
	}
	return (1);
}
/**
 * _myExit - buildin exit function
 * @params: parameters
 */
void _myExit(param_t *params)
{
	int status = 0;

	if (!params->args[1])
	{
		status = params->status;
		free_params(params);
		exit(status);
	}
	if (validNum(params->args[1]))
	{
		status = _atoi((params->args)[1]);
		if (status == -1)
		{
			write_error(params, "Illegal number: ");
			write(STDERR_FILENO, params->args[1],
			      _strlen(params->args[1]));
			write(STDERR_FILENO, "\n", 1);
			params->status = 2;
			return;
		}
		free_params(params);
		exit(status);
	}
	else
	{
		params->status = 2;
		write_error(params, "Illegal number: ");
		write(STDERR_FILENO, params->args[1],
		      _strlen(params->args[1]));
		write(STDERR_FILENO, "\n", 1);
	}
}
