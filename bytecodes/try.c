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
		printf("%d\n", temp->n);
	temp = temp->next;
	free(temp);
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
	temp = head;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
/**
 * tokenize - tokenizes a string into tokens
 * @str: the string to be tokenized
 * @line_number: number of current line
 * @head: head of the stack
*/
void tokenize(char *str, int line_number, stack_t **head)
{
	const char *delim = " \n";
	char *arg1, *arg2;

	arg1 = strtok(str, delim);
	if (!arg1)
		return;
	arg2 = strtok(NULL, delim);
	if (*arg1 == '#')
		return;
	if (strcmp(arg1, "push") == 0)
	{
		if (!isnumber(arg2))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		*head = add_node(*head, atoi(arg2));
	}
	else
		func_calls(head, arg1, line_number);
}
/**
 * main - entry point of the code
 * @argc: number of arguments
 * @argv: list of arguments
 * Return: 0 on success, 1 otherwise
*/
int main(int argc, char **argv)
{
	char *lineptr = NULL;
	size_t n = 0;
	int line_number = 0;
	ssize_t no_read_chars;
	stack_t *head = NULL;
	FILE *fp;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = open_file(argv[1]);
	while ((no_read_chars = getline(&lineptr, &n, fp)) > 0)
	{
		line_number++;
		tokenize(lineptr, line_number, &head);
	}
	free(lineptr);
	fclose(fp);
	free_stack(head);
	return (EXIT_SUCCESS);
}
