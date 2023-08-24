#include "monty.h"
/**
 * open_file - opens a file
 * @file_name: name of the file
 * Return: returns pointer to a FILE on success
 * and null otherwise
*/
FILE *open_file(char *file_name)
{
	FILE *fp;
	int flag;

	if (!file_name)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	flag = access(file_name, F_OK);
	if (flag == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	fp = fopen(file_name, "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	return (fp);
}
