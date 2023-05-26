#include "monty.h"
/**
 * stack_push - this function adds a node to the stack
 * @head: the head of the stack
 * @counter: line_number
 * Return: no return
 */
void stack_push(stack_t **head, unsigned int counter)
{
	int node, i = 0, flag = 0;

	if (store.arg)
	{
		if (store.arg[0] == '-')
			i++;
		for (; store.arg[i] != '\0'; i++)
		{
			if (store.arg[i] > 57 || store.arg[i] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(store.file);
			free(store.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(store.file);
		free(store.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	node = atoi(store.arg);
	if (store.flag_change == 0)
		addnode(head, node);
	else
		addqueue(head, node);
}
