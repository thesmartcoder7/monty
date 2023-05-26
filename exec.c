#include "monty.h"
/**
* prog_exec - this executes the given opcode
* @head:  the head of the  stack
* @counter: code line position
* @file: the poiner to monty file
* @content: line content
* Return: nothing
*/
int prog_exec(char *content, stack_t **head, unsigned int counter, FILE *file)
{
	instruction_t op_maps[] = {
		{"push", stack_push}, {"pall", stack_pall}, {"pint", stack_pint},
		{"pop", stack_pop}, {"swap", stack_swap}, {"add", stack_add},
		{"nop", stack_nop}, {"sub", stack_sub}, {"div", stack_div},
		{"mul", stack_mul}, {"mod", stack_mod}, {"pchar", stack_pchar},
		{"pstr", stack_pstr}, {"rotl", stack_rotl}, {"rotr", stack_rotr},
		{"queue", stack_queue}, {"stack", sm_stack}, {NULL, NULL}
	};

	unsigned int i = 0;
	char *op_ext;

	op_ext = strtok(content, " \n\t");

	if (op_ext && op_ext[0] == '#')
		return (0);

	store.arg = strtok(NULL, " \n\t");

	while (op_maps[i].opcode && op_ext)
	{
		if (strcmp(op_ext, op_maps[i].opcode) == 0)
		{	op_maps[i].f(head, counter);
			return (0);
		}
		i++;
	}

	if (op_ext && op_maps[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op_ext);
		fclose(file);
		free(content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	return (1);
}
