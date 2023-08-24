#include "monty.h"

int main(int argc, char **argv)
{
    char *lineptr = NULL, **tokenz;
    size_t n = 0;
    int line_number = 0;
    ssize_t no_read_chars;
    int fd;
    FILE *fp;
    char buffer[1024];

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file");
        exit(EXIT_FAILURE);
    }

    fp = open_file(argv[1]);
    
    while((no_read_chars = getline(&lineptr, &n, fp))>0)
    {
        printf("line 23\n");
        printf("%s$", lineptr);
        tokenize(lineptr, tokenz);
        printf("line 25\n");
        line_number++;
        if (!tokenz[0])
            continue;
        printf("%s -- %s -> %d\n", tokenz[0], tokenz[1], line_number);
    }
    return (EXIT_SUCCESS);
}