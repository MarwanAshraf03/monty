#include "monty.h"

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