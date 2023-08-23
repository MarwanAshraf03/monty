#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    int fd, n;
    char buffer[1024];
    fd = open("bytecodes/001.m", O_RDONLY);
    if(!fd)
        return EXIT_FAILURE;
    while ((n = read(fd, buffer, 1024)) > 0)
    {
        write(STDOUT_FILENO, buffer, n);
    }
    
    return EXIT_SUCCESS;
}