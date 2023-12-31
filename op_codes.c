#include "monty.h"
/**
 * pall - prints all elements in stack
 * @stack: head of the stack
 * @line_number: number of line
*/
void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack)
		return;
	temp = (*stack);
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint - prints value at top
 * @stack: head of the stack
 * @line_number: number of current line
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
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
		new->next = NULL;
		new->prev = NULL;
		new->n = n;
		head = new;
	}
	else
	{
		new->next = head;
		new->prev = NULL;
		new->n = n;
		head = new;
	}
	return (head);
}
/**
 * free_stack - frees stack
 * @head: head of the stack
*/
void free_stack(stack_t *head)
{
	stack_t *temp;

	if (!head)
		return;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
/**
 * pop - removes top element of the stack
 * @stack: head of the stack
 * @line_number: number of current line
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack);
	if (temp->next)
	{
		(*stack) = temp->next;
		(*stack)->prev = NULL;
	}
	else
		(*stack) = NULL;
	free(temp);
}
