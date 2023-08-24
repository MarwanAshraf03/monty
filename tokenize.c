#include "monty.h"

/**
 * tokenize - tokenizes a string into tokens
 * @str: the string to be tokenized
 * @argv: string array to have tokens
*/
void tokenize(char *str, int line_number, stack_t *head)
{
	const char *delim = " \n";
	char *arg1, *arg2;
	stack_t *added;

	arg1 = strtok(str, delim);
	if (!arg1)
		return;
	arg2 = strtok(NULL, delim);
	/* to check if the value of second string is numeric*/
	if (strcmp(arg1, "push") == 0 && isnumber(arg2))
	{
		printf("tokenize: line 21\n");
		if (!head)
		{
			printf("tokenize: line 24\n");
			head = malloc(sizeof(stack_t));
			head->n = atoi(arg2);
			head->next = NULL;
			head->prev = NULL;
		}
		else
		{
			added = malloc(sizeof(stack_t));
			added->prev = NULL;
			added->next = head;
			added->n = atoi(arg2);
			head = added;
		}
	}
	else
		func_calls(&head, arg1, line_number);
}