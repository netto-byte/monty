#include "monty.h"

/**
 * get_command - Executes a command
 */
void get_command(void)
{
	instruction_t get[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub}, {"div", _div},
		{"mul", mul}, {"mod", mod}, {"pchar", pchar},
		{NULL, NULL}
	};
	int i;
	char *cmd;

	cmd = strtok(data.command, " \t\n");
	if (cmd == NULL || *cmd == '#')
		return;

	for (i = 0; get[i].opcode; i++)
	{
		if ((strcmp(get[i].opcode, cmd)) == 0)
		{
			get[i].f(&(data.stack), data.line_number);
			return;
		}
	}

	if (get[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
				data.line_number, cmd);
		free_data();
		exit(EXIT_FAILURE);
	}
}
