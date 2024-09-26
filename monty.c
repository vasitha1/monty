#define _GNU_SOURCE
#include "monty.h"

/**
 * remove_spaces - function that removes unwanted spaces from string
 * @str: String space to be removed
 *
 * Return: String without unwanted spaces
 */
char *remove_spaces(char *str)
{
	int i = 0;
	int j = 0;
	char *new_str = malloc(strlen(str) + 1);

	if (new_str == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	while (str[i] == ' ')
		i++;

	while (str[i] != '\0' && str[i] != '$')
	{
		if (str[i] != ' ' || (j > 0 && new_str[j - 1] != ' '))
		{
			new_str[j] = str[i];
			j++;
		}
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}

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
 * @tok2: Second token representing argument
 * @line_num: Number of the line.
 * @line: String to be freed if exiting
 * @s: stack
 *
 * Return: Void
 */
void execute_line(char *tok, char *tok2, int line_num, char *line, stack_t **s)
{
	if (strcmp(tok, "push") == 0)
	{
		if (tok2 == NULL ||
		(atoi(tok2) == 0 && strcmp(tok2, "0") != 0))
		{
			fprintf(stderr, "L%d: unknown instruction %s",
				line_num, line);
			free(line);
			exit(EXIT_FAILURE);
		}
		push(s, tok2);
	}
	else if (strcmp(tok, "pall") == 0)
	{
		if (tok2 != NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s",
				line_num, line);
			free(line);
			exit(EXIT_FAILURE);
		}
		pall(*s);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s",
			line_num, line);
		free(line);
		exit(EXIT_FAILURE);
	}
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
	char *token, *token2, *new_line;

	char *line = NULL;
	size_t len = 0;
	int line_number = 0;
	stack_t *stack = NULL;

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		new_line = remove_spaces(line);
		token = strtok(new_line, " ");
		token2 = strtok(NULL, " ");

		if (token == NULL)
		{
			free(new_line);
			continue;
		}
		execute_line(token, token2, line_number, new_line, &stack);
		free(new_line);
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
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	read_and_execute(file);
	fclose(file);
	return (0);
}

