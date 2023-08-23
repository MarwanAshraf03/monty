#include "monty.h"

/**
 * tokenize - tokenizes a string into tokens
 * @str: the string to be tokenized
 * @argv: string array to have tokens
*/
void tokenize(char *str, char **argv)
{
	char *token;
	const char *delim = " \n";
	int counter;

	token = strtok(str, delim);
	for (counter = 0; token != NULL; counter++)
	{
		argv[counter] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[counter], token);
		token = strtok(NULL, delim);
	}
	argv[counter] = NULL;
}