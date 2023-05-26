#include "monty.h"
/**
 * stack_pop - prints the top
 * @head: the head of the stack
 * @counter: code line position
 * Return: nothing
 */
void stack_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(store.file);
		free(store.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
