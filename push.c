#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: Pointer to a stack
 * @line_number: command index in a monty file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *num = strtok(NULL, " \t\n");

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_data();
		exit(EXIT_FAILURE);
	}

	if (num == NULL || not_number(num))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(new);
		free_data();
		exit(EXIT_FAILURE);
	}

	new->prev = NULL;
	new->n = atoi(num);

	if (*stack == NULL)
		new->next = NULL;
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;
}

/**
 * not_number - Checks if a string is not a number
 * @str: String to validate
 *
 * Return: 1 if not a number, otherwise 0
 */
int not_number(char *str)
{
	if (*str == '-')
		str++;

	while (*str)
	{
		if (!isdigit(*str))
			return (1);
		str++;
	}
	return (0);
}
