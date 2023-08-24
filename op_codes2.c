#include "monty.h"
/**
 * swap - swap top two element of the stack
 * @stack: head of the stack
 * @line_number: number of current line
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;
	int mid_val;

	if (!*stack || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp1 = (*stack);
	temp2 = (*stack)->next;
	mid_val = temp1->n;
	temp1->n = temp2->n;
	temp2->n = mid_val;
}
/**
 * add - add top two element of the stack
 * @stack: head of the stack
 * @line_number: number of current line
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;

	if (!*stack || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp1 = (*stack);
	temp2 = (*stack)->next;
	temp2->n = temp1->n + temp2->n;
	(*stack) = temp2;
	free(temp1);
}