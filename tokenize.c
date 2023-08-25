#include "monty.h"

/**
 * tokenize - tokenizes a string into tokens
 * @str: the string to be tokenized
 * @line_number: number of current line
 * @head: head of the stack
*/
void tokenize(char *str, int line_number, stack_t **head)
{
	const char *delim = " \n";
	char *arg1, *arg2;

	if (!str)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	arg1 = strtok(str, delim);
	if (!arg1)
		return;
	arg2 = strtok(NULL, delim);
	if (*arg1 == '#')
		return;
	if (strcmp(arg1, "push") == 0)
	{
		if (!isnumber(arg2))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		*head = add_node(*head, atoi(arg2));
	}
	else
		func_calls(head, arg1, line_number);
}
