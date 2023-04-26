#ifndef LISTSH
#define LISTSH

#include <unistd.h>

/**
 * struct list_s - singly linked list node
 * @str: string data
 * @val: value string data
 * @len: length of the string data
 * @valLen: length of the value string data
 * @next: pointer to the next node in the list
 *
 * Description: This struct represents a node in a singly linked list
 * for the ALX shell project
*/

typedef struct list_s
{
	char *str;
	char *val;
	unsigned int len;
	unsigned int valLen;
	struct list_s *next;
} list_t;

int _putchar(char c);

size_t print_list(list_t *h);

size_t list_len(list_t *h);

list_t *add_node(list_t **head, char *str, char *val);

void free_list(list_t *head);

list_t *get_node(list_t *head, char *str);


#endif
