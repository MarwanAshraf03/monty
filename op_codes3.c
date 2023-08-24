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
/**
 * pchar - prints char value of top element
 * @stack: head of the stack
 * @line_number: number of current line
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (
		((*stack)->n < 'a' || (*stack)->n > 'z')
		&&
		((*stack)->n < 'A' || (*stack)->n > 'Z')
		)
{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
