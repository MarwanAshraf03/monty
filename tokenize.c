#include "monty.h"

/**
 * tokenize - tokenizes a string into tokens
 * @str: the string to be tokenized
 * @argv: string array to have tokens
*/
void tokenize(char *str, int line_number)
{
	const char *delim = " \n";
	char *arg1, *arg2;
	int push_value;
	int counter;

	arg1 = strtok(str, delim);
	if (!arg1)
		return;
	arg2 = strtok(NULL, delim);
	/* to check if the value of second string is numeric*/
	if (strcmp(arg1, "push") == 0)
		while (*arg2)
		{
			if (!isdigit(*arg2))
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			arg2++;
		}
		push_value = atoi(arg2);
		printf("%s -- %s -> %d\n", arg1, arg2, line_number);
}