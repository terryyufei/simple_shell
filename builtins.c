#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"
#include "lists.h"
#include "main.h"

/**
 * get_builtin - Get built-in function
 * @params: Pointer to the param_t struct containing command parameters
 *
 * Description: Searches for a built-in function based on the first argument
 * in the param_t struct. Returns a function pointer to the corresponding
 * built-in function if found, or NULL if not found.
 *
 * Return: Function pointer to the built-in function. NULL if not found.
 */

void (*get_builtin(param_t *params))(param_t *)
{
	op_t ops[] = {
		{"exit", _myExit},
		{"clear", _clear},
		{"env", _printenv},
		{"setenv", _setenv},
		{"cd", _cd},
		{"unsetenv", _unsetenv},
		{"alias", _alias},
		{NULL, NULL},
	};
	op_t *op = ops;

	while (op->name)
	{
		if (!_strcmp(params->args[0], op->name))
			return (op->func);
		op++;
	}
	return (NULL);
}
