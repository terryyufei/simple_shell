#include <unistd.h>
#include <stdlib.h>
#include "shell.h"
#include "main.h"
#define BUFFER_SIZE 4096
#define READ_SIZE 1024

/**
 * rlLine - realloc the line buffer
 * @line: to be buffered
 * @oldSize: something borrowed
 * @newSize: something blue
 *
 * Return: new allocated buffer
 */
char *rlLine(char **line, unsigned int oldSize, unsigned int newSize)
{
	char *newLine = NULL;
	unsigned int i;

	newLine = malloc(newSize);
	if (newLine)
	{
		for (i = 0; i < oldSize; i++)
			newLine[i] = (*line)[i];
		free(*line);
		*line = newLine;
	}
	return (newLine);
}
/**
 * _getline - fetches a line of chars from stdin
 * @params: parameters
 *
 * Return: number of char read
 */
int _getline(param_t *params)
{
	char *line = NULL;
	static unsigned int bufSize = BUFFER_SIZE;
	char *writeHead = line;
	unsigned int len;

	line = malloc(BUFFER_SIZE);
	do {
		len = read(0, writeHead, BUFFER_SIZE);
		if (len == 0)
			break;
		writeHead += len;
		if (writeHead >= (line + BUFFER_SIZE - 1 - READ_SIZE))
		{
			line = rlLine(&line, bufSize, bufSize * 2);
			bufSize *= 2;
		}
	} while (*(writeHead - 1) != '\n');

	free(params->buffer);
	params->buffer = line;
	if (len == 0)
		return (-1);
	return (_strlen(params->buffer));
}
