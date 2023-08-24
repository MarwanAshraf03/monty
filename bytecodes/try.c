#include <stdio.h>
#include <stdlib.h>

typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


stack_t *node_init(stack_t **head, int n)
{
    *head = malloc(sizeof(stack_t));

    (*head)->n = n;
    (*head)->next = NULL;
    (*head)->prev = NULL;
    return (*head);
}
void main(void)
{
    stack_t *head = NULL;

    printf("%d\n", !head);
    head = node_init(&head, 5);
    printf("%d\n", !head);
}
