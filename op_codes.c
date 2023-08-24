#include "monty.h"
/**
 * pall - prints all elements in stack
 * @stack: head of the stack
 * @line_number: number of line
*/
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp;
	int counter = 0;

	if (!stack || !*stack)
		return;
	temp = (*stack);
	while (temp->next)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
		counter++;
		printf("counter -> %d\n", counter);
	}
		printf("%d\n", temp->n);
}

/**
 * add_node - initializes node
 * @head: node to be initialized
 * @n: value to be put in node
 * Return: the new node
*/
stack_t *add_node(stack_t *head, int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (head == NULL)
	{
		printf("op_codes: line 35\n");
		new->next = NULL;
		new->prev = NULL;
		new->n = n;
		head = new;
	}
	else
	{
		printf("op_codes: line 43\n");
		new->next = head;
		new->prev = NULL;
		new->n = n;
		head = new;
	}
	return (head);
}
