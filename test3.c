#include "monty.h"

int main(int argc, char **argv)
{
    char *lineptr = NULL, **tokenz;
    size_t n = 0;
    int line_number = 0;
    ssize_t no_read_chars;
    int token_no;
    int fd;
    FILE *fp;
    char buffer[1024];

    fp = fopen(argv[1], "r");
    if(!fp)
        return EXIT_FAILURE;
    
    while((no_read_chars = getline(&lineptr, &n, fp))>0)
    {
    tokenize(lineptr, tokenz);
    line_number++;
    if (!tokenz[0])
    continue;
    printf("%s -- %s -> %d\n", tokenz[0], tokenz[1], line_number);
    }
    return EXIT_SUCCESS;
}