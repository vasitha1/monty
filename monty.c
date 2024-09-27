#define _GNU_SOURCE
#include "monty.h"

/**
 * count_line - function that counts lines of a file
 * @file: Name of file whoes lines are to be counted
 *
 * Return: Number of lines.
 */
int count_line(FILE *file)
{
	char ch;

	int count = 0;

	while ((ch = fgetc(file)) != EOF)
	{
		if (ch == '\n')
			count++;
	}
	fclose(file);

	if (count > 0 && ch != '\n')
		count++;
	return (count);
}

/**
 * execute_line - Executes a line in the file
 * @tok: First tocken representing command
 * @line_number: Number of the line.
 * @s: stack
 *
 * Return: Void
 */
void execute_line(char *tok, int line_number, stack_t **s)
{
	int i = 0;

	instruction_t validate[] = {
		{"push", o_push},
		{"pall", o_pall},
		{NULL, NULL}
		};

	while (validate[i].opcode != NULL)
	{
		if (strcmp(validate[i].opcode, tok) == 0)
		{
			validate[i].f(s, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n",
		line_number, tok);
		exit(EXIT_FAILURE);
}

/**
 * read_and_execute - Function that reads from file and executes command
 * @file: File to read from
 *
 * Return: void
 */
void read_and_execute(FILE *file)
{
	ssize_t read;
	char *token;

	char *line = NULL;
	size_t len = 0;
	int line_number = 0;
	stack_t *stack = NULL;

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		token = strtok(line, "\n\t\r ");

		if (token == NULL || token[0] == '#')
		{
			continue;
		}
		execute_line(token, line_number, &stack);
	}
	free(line);
}


/**
 * main - entry point
 * @argv: array of command and file
 * @argc: argument count
 *
 * Descrition: Program that opens a file given on CLI argument and executes.
 * Return: 0 Always(sucess)
 */
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read_and_execute(file);
	fclose(file);
	return (0);
}

