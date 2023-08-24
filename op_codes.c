#include "monty.h"

void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
    stack_t *temp;

    printf("op_codes.c: pall: line 35\n");
    if (!stack || !*stack)
    {
        printf("op_codes.c: pall: line 38\n");
        return;
    }
    temp = (*stack);
    printf("%d\n", temp->n);
    while (temp->next)
    {
        printf("op_codes.c: pall: line 44\n");
        printf("%d\n", temp->n);
        temp = temp->next;
    }
    free(temp);
}

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
    return(*stack);
}