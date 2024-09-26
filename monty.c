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
		if (strcmp(token, "push") == 0)
		{
			if (token2 != NULL)
				push(token2);
		}
		else if (strcmp(token, "pall") == 0)
			pall();
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s",
				line_number, token);
			free(new_line);
			free(line);
			exit(EXIT_FAILURE);
		}
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
		fprintf(stderr, "Error: Can't open file <file>");
		exit(EXIT_FAILURE);
	}
	read_and_execute(file);
	fclose(file);
	return (0);
}

