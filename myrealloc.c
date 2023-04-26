#include <stdlib.h>
#include <stdio.h>
/**
 * _realloc - reallocates a memory block using malloc
 * @ptr: old block
 * @old_size: size of the old block
 * @new_size: size of the new block
 *
 * Return: pointer to new block
 */
char **_realloc(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newPtr = NULL;
	unsigned int num, i;

	if (!ptr)
	{
		free(ptr);
		return (malloc(sizeof(*ptr) * new_size));
	}
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);
	num = old_size < new_size ? old_size : new_size;
	newPtr = malloc(8 * new_size);
	if (newPtr)
	{
		for (i = 0; i < new_size; i++)
			newPtr[i] = NULL;
		for (i = 0; i < num; i++)
			newPtr[i] = ptr[i];
		free(ptr);
	}
	return (newPtr);
}
