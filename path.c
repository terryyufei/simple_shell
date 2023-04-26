#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "main.h"
#include "shell.h"
#include "lists.h"
/**
 * get_file - get correct path to a command file
 * @params: parameters
 *
 * Return: string of valid path to command file, NULL if not found
 * The string needs to be freed
 */
char *get_file(param_t *params)
{
	char *path = NULL;
	char *exePath = NULL, *exeArg = NULL, *tmp = NULL;
	char *state = NULL;

	if (access(params->args[0], F_OK | X_OK) == 0)
	{
		free(path);
		return (_strdup(params->args[0]));
	}
	if (errno == EACCES)
	{
		params->status = 126;
		write_error(params, "Permission denied\n");
		return (NULL);
	}
	path = _getenv("PATH", params);
	if (!path)
	{
		write_error(params, "not found\n");
		return (NULL);
	}
	exePath = _strtok(path, ":", &state);
	while (exePath)
	{
		tmp = exeArg;
		exeArg = str_concat(exePath, "/");
		free(tmp);
		tmp = exeArg;
		exeArg = str_concat(exeArg, params->args[0]);
		free(tmp);
		if (access(exeArg, F_OK) == 0)
		{
			free(path);
			free(exePath);
			return (exeArg);
		}
		free(exePath);
		exePath = _strtok(path, ":", &state);
	}
	params->status = 127;
	write_error(params, "not found\n");
	free(path);
	free(exePath);
	free(exeArg);
	return (NULL);
}

