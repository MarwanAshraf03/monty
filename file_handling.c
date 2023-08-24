#include "monty.h"

FILE *open_file(char *file_name)
{
	FILE *fp;
	int flag;

	fp = fopen(file_name, "r");
	flag = access(file_name, F_OK);
	if (!fp || flag)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	return (fp);
}
