#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
stack_t *add_node(stack_t *head, int n)
{
    stack_t *new = malloc(sizeof(stack_t));

    if (head == NULL)
    {
        printf("line 16\n");
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
int main(void)
{
    stack_t *head = NULL;

    head = add_node(head, 1);
    head = add_node(head, 2);
    head = add_node(head, 3);
    head = add_node(head, 4);
    head = add_node(head, 5);

    while (head->next)
    {
        printf("%d\n", head->n);
        head = head->next;
    }
    printf("%d\n", head->n);
    return (0);
}