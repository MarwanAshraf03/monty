#include "monty.h"
/**
 * pall - prints all elements in stack
 * @stack: head of the stack
 * @line_number: number of line
*/
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack)
		return;
	temp = (*stack);
	while (temp->next)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	free(temp);
}
/**
 * node_init - initializes node
 * @stack: node to be initialized
 * @n: value to be put in node
 * Return: the new node
*/
stack_t *node_init(stack_t **stack, int n)
{
	stack_t *added = malloc(sizeof(stack_t));

	if (!added)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	added->n = n;
	added->next = NULL;
	added->prev = NULL;
	*stack = added;
	return (*stack);
}
