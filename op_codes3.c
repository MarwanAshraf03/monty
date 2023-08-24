#include "monty.h"
/**
 * _mul - multiplies top two element of the stack
 * @stack: head of the stack
 * @line_number: number of current line
*/
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;

	if (!*stack || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp1 = (*stack);
	temp2 = (*stack)->next;
	temp2->n = temp2->n * temp1->n;
	(*stack) = temp2;
	free(temp1);
}
/**
 * _mod - reminder of second top / top elements
 * @stack: head of the stack
 * @line_number: number of current line
*/
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;

	if (!*stack || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp1 = (*stack);
	if (temp1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp2 = (*stack)->next;
	temp2->n = temp2->n % temp1->n;
	(*stack) = temp2;
	free(temp1);
}
