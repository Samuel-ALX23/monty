#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} bus_t;

extern bus_t bus;

typedef struct instruction_s
{
	char *opcode;
	void (*func)(stack_t **stack, unsigned int line_number);
} instruction_t;

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

void print_all_stack_values(stack_t **head, unsigned int counter);
void free_stack(stack_t *current);
void insert_node(stack_t **head, int data);
int process_instruction(char *instruction, stack_t **stack, unsigned int instruction_number, FILE *bytecode_file);

void pushElement(stack_t **stackHead, unsigned int lineNumber);
void print_integer(stack_t **head, unsigned int instruction_number);
void f_pop(stack_t **stack, unsigned int line_number);
void swap_top_two_elements(stack_t **head, unsigned int lineNumber);
void add_stack(stack_t **head, unsigned int counter);
void _nop_handle(stack_t **head, char *argument, unsigned int instruction_number);
void subtract_top_two_elements(stack_t **head, unsigned int lineNumber);
void divide_elements(stack_t **head, unsigned int counter);
void handle_mudulo(stack_t **head, char *argument, unsigned int instruction_number);
void handle_modulo(stack_t **head, char *argument, unsigned int instruction_number);
void dis_character(stack_t **head, unsigned int instruction_number);
void f_rotate_left(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void rotate_right(stack_t **head);
void set_lifo(stack_t **head);
void _string_dis(stack_t **stack);


#endif
