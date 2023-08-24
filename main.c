#include "monty.h"

int main(int argc, char **argv)
{
    char *lineptr = NULL;
    size_t n = 0;
    int line_number = 0;
    ssize_t no_read_chars;
    stack_t *head = NULL;
    /* int fd; */
    FILE *fp;
    /* char buffer[1024]; */

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file");
        exit(EXIT_FAILURE);
    }

    fp = open_file(argv[1]);
    
    while((no_read_chars = getline(&lineptr, &n, fp))>0)
    {
        line_number++;
        tokenize(lineptr, line_number, head);
    }
    return (EXIT_SUCCESS);
}