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
/**
 * nop - does nothing
 * @stack: head of the stack
 * @line_number: number of current line
*/
void nop(
	__attribute__((unused))stack_t **stack,
	__attribute__((unused))unsigned int line_number
	)
{
	(void)stack;
	(void)line_number;
}
/**
 * sub - subtract top two element of the stack
 * @stack: head of the stack
 * @line_number: number of current line
*/
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;

	if (!*stack || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp1 = (*stack);
	temp2 = (*stack)->next;
	temp2->n = temp2->n - temp1->n;
	(*stack) = temp2;
	free(temp1);
}
/**
 * _div - divides top two element of the stack
 * @stack: head of the stack
 * @line_number: number of current line
*/
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;

	if (!*stack || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp1 = (*stack);
	if (temp1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp2 = (*stack)->next;
	temp2->n = temp2->n / temp1->n;
	(*stack) = temp2;
	free(temp1);
}
