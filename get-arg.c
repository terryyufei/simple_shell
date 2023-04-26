#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * get_arg - Returns a formatted argument based on the type specifier.
 *
 * @type: Type specifier indicating the desired formatting ('c', 's', 'd', 'i',
 *         'b', 'r', 'R').
 * @...: Variable number of arguments depending on the type specifier.
 *
 * This function takes a type specifier and a variable number of arguments and
 * a formatted string representation of the argument based on the typ specifier
 *
 *    The supported type specifiers are:
 *   - 'c': Char argument is passed as int and returned as a string.
 *   - 's': String argument is passed as char* and returned as a string.
 *   - 'd' or 'i': Integer argument is passed as int and returned as a string.
 *   - 'b': Integer argument is passed as int and returned as a binary string.
 *   - 'r': String argument is passed as char* and returned as reversed string
 *   - 'R': String argument is passed as char* and returned as a ROT13 string.
 *
 * Return: A dynamically allocated string representation of the argument based
 *        on the type specifier,
 *         or NULL if an unsupported type specifier is provided.
 */


char *get_arg(char type, ...)
{
	va_list params;

	va_start(params, type);
	switch (type)
	{
	case 'c':
		return (get_char(va_arg(params, int)));
	case 's':
		return (get_string(va_arg(params, char*)));
	case 'd':
	case 'i':
		return (get_number(va_arg(params, int)));
	case 'b':
		return (get_binary(va_arg(params, int)));
	case 'r':
		return (get_rev(va_arg(params, char *)));
	case 'R':
		return (get_rot13(va_arg(params, char *)));
	default:
		return (NULL);/* Error */
	}
}
