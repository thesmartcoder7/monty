#include "monty.h"
/**
 * stack_pint - prints the top
 * @head: the head of the stack
 * @counter: position of code line (line number)
 * Return: nothing
 */
void stack_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(store.file);
		free(store.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
