#include "monty.h"

/**
 * stack - Sets the format of the data to a stack,
 * accordingly
 * @stack: pointer to a stack
 * @line_number: current command line in monty_file
 *
 * Return: void.
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	data.FIFO = 0;
}

/**
 * queue - Sets the format of the data to a queue
 * @stack: pointer to a stack
 * @line_number: current command line in monty_file
 *
 * Return: void.
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	data.FIFO = 1;
}

