#include "monty.h"

data_t data = {0, NULL, NULL, NULL};
/**
 * main - monty code interpreter
 * @argc: Number of arguments passed to program
 * @argv: Array of arguments passed to program
 *
 * Return: Always 0 upon success.
 */
int main(int argc, char *argv[])
{
	ssize_t r = 0;
	size_t n = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	data.file = fopen(argv[1], "r");
	if (data.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (r != -1)
	{
		data.command = NULL;
		data.line_number += 1;
		r = getline(&(data.command), &n, data.file);
		if (r > 0)
			get_command();
		free(data.command);
	}
	free_stack(&(data.stack));
	fclose(data.file);

	return (0);
}
