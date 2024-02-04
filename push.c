#include "monty.h"

/**
 * push - Adds a new data to stack.
 * @stack: pointer to a stack
 * @line_number: current command line number of monty_file
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *num = strtok(NULL, " \t\n");

	(void)stack;
	if (num == NULL || not_number(num))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_data();
		exit(EXIT_FAILURE);
	}

	if (data.FIFO)
		add_at_end(num);
	else
		add_at_beg(num);
}

/**
 * not_number - Checks if a token content characters otherthan digits
 * @token: token for validation
 *
 * Return: 1 if it contain character(s) otherthan digits, otherwise 0.
 */
int not_number(char *token)
{
	if (*token == '-')
		token++;

	while (*token)
	{
		/* check if there's a non digit character */
		if (!isdigit(*token))
			return (1);
		token++;
	}

	return (0);
}

/**
 * add_at_beg - Adds a new node at the beginning of a stack
 *
 * Return: void.
 */
void add_at_beg(char *num)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_data();
		exit(EXIT_FAILURE);
	}

	new->prev = NULL;
	new->n = atoi(num);

	if (data.stack == NULL)
		new->next = NULL;
	else
		new->next = data.stack;

	data.stack = new;
	data.size++;
}

/**
 * add_at_end - Adds a new node at the end of a stack
 *
 * Return: void.
 */
void add_at_end(char *num)
{
	stack_t *new, *ptr = data.stack;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_data();
		exit(EXIT_FAILURE);
	}

	new->n = atoi(num);
	new->next = NULL;

	if (data.stack == NULL)
	{
		new->prev = NULL;
		data.stack = new;
	}
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
		new->prev = ptr;
	}
	data.size++;
}
