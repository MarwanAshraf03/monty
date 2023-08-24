#include "monty.h"

FILE *open_file(char *file_name)
{
    FILE *fp;

    fp = fopen(file_name, "r");
    if (!fp)
    {
        fprintf(stderr, "Error: Can't open file %s\n", file_name);
        exit(EXIT_FAILURE);
    }

    return (fp);
}