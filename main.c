#include "monty.h"
/**
 * main - entry point of the code
 * @argc: number of arguments
 * @argv: list of arguments
 * Return: 0 on success, 1 otherwise
*/
int main(int argc, char **argv)
{
	char *lineptr = NULL;
	size_t n = 0;
	int line_number = 0;
	ssize_t no_read_chars;
	stack_t *head = NULL;
	FILE *fp;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	fp = open_file(argv[1]);
	while ((no_read_chars = getline(&lineptr, &n, fp)) > 0)
	{
		line_number++;
		tokenize(lineptr, line_number, &head);
	}
	return (EXIT_SUCCESS);
}
