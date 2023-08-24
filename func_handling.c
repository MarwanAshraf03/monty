#include "monty.h"
/**
 * func_calls - calls specific function
 * @stack: head of the function
 * @arg: name of the function
 * @line_number: number of current line
*/
void func_calls(stack_t **stack, char *arg, int line_number)
{
	instruction_t inst[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};
	int iterator = 0, found = 0;

	while (inst[iterator].opcode)
	{
		if (strcmp(arg, inst[iterator].opcode) == 0)
		{
			found = 1;
			inst[iterator].f(stack, line_number);
		}
		iterator++;
	}
	if (!found)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, arg);
		exit(EXIT_FAILURE);
	}
}
