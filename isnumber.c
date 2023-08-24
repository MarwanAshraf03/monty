#include "monty.h"

/**
 * isnumber - checks if string is a number
 * @arg2: string to be determined
 * Return: 1 if number, 0 otherwise
*/
int isnumber(char *arg2)
{
    while (*arg2)
	{
		if (*arg2 == '-')
			arg2++;
		if (!isdigit(*arg2))
			return (0);
		arg2++;
	}
    return 1;
}