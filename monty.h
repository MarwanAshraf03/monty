#ifndef MONTY_H
#define MONTY_H
#define  _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#define USAGE "USAGE: monty file\n"
#define FILE_NO_OPEN "Error: Can't open file %s\n"
#define BAD_INST "L%d: unknown instruction %s\n"
#define MALLOC_FAIL "Error: malloc failed\n"
#define PUSH "L%d: usage: push integer\n"
#define PINT "L%d: can't pint, stack empty\n"
#define POP "L%d: can't pop an empty stack\n"
#define SWAP "L%d: can't swap, stack too short\n"
#define ADD "L%d: can't add, stack too short\n"
#define SUB "L%d: can't sub, stack too short\n"
#define DIV_FAIL "L%d: can't div, stack too short\n"
#define DIV_ZERO "L%d: division by zero\n"
#define MUL "L%d: can't mul, stack too short\n"
#define MOD_FAIL "L%d: can't mod, stack too short\n"
#define PCHAR_FAIL "L%d: can't pchar, stack empty\n"
#define PCHAR_OUT_BOUNDS "L%d: can't pchar, value out of range\n"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;

/* file_handling.c */
FILE *open_file(char *file_name);

/* tokenize.c */
void tokenize(char *str, int line_number, stack_t **head);

/* op_codes.c */
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
stack_t *add_node(stack_t *head, int n);
void free_stack(stack_t *head);
void pop(stack_t **stack, unsigned int line_number);

/* op_codes2.c */
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(__attribute__((unused))stack_t **stack, __attribute__((unused))unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);

/* op_codes3.c */
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, __attribute__((unused))unsigned int line_number);

/* func_handling.c */
void func_calls(stack_t **stack, char *arg1, int line_number);

/* isnumber.c */
int isnumber(char *arg2);

#endif
