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
		{NULL, NULL}
	};
	int iterator = 0;

	while (inst[iterator].opcode)
	{
	if (strcmp(arg, inst[iterator].opcode) == 0)
	{
		printf("func_handling.c: line 15, %s\n", inst[iterator].opcode);
		inst[iterator].f(stack, line_number);
	}
	iterator++;
}
}
