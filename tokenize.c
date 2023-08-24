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

	if (!str)
	{
		printf("line 16\n");
		argv[0] = argv[1] = argv[2] = NULL;
		return;
	}
	token = strtok(str, delim);
	argv[0] = malloc(sizeof(char) * strlen(token));
	strcpy(argv[0], token);
	if (!str)
	{
		printf("line 16\n");
		argv[0] = argv[1] = argv[2] = NULL;
		return;
	}
	token = strtok(NULL, delim);
	argv[1] = malloc(sizeof(char) * strlen(token));
	strcpy(argv[1], token);

	// for (counter = 0; token != NULL; counter++)
	// for (counter = 0; counter < 2; counter++)
	// {
	// 	if (token == NULL)
	// 	{
	// 		// counter--;
	// 		continue;
	// 	}
	// 	argv[counter] = malloc(sizeof(char) * strlen(token));
	// 	strcpy(argv[counter], token);
	// 	token = strtok(NULL, delim);
	// }
	argv[2] = NULL;
	// argv[counter] = NULL;
}