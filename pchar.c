#include "monty.h"
/**
 * stack_pchar - this prints the char at the top of the stack
 * @head: the head of the stack
 * @counter: code line position
 * Return: nothing
*/
void stack_pchar(stack_t **head, unsigned int counter)
{
	stack_t *h;

	h = *head;

	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(store.file);
		free(store.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(store.file);
		free(store.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", h->n);
}
