#define _GNU_SOURCE
#include "monty.h"
carrier store = {NULL, NULL, NULL, 0};

/**
 * main - the monty code interpreter
 * @argc: number of arguments provided
 * @argv: monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t curr_line = 1;
	stack_t *head_ptr = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	store.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (curr_line > 0)
	{
		content = NULL;
		curr_line = getline(&content, &size, file);
		store.content = content;
		counter++;
		if (curr_line > 0)
		{
			prog_exec(content, &head_ptr, counter, file);
		}
		free(content);
	}

	free_stack(head_ptr);
	fclose(file);
	return (0);
}
