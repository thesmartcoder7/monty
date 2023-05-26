#include "monty.h"
/**
 * stack_mod - this gets the division of the 2nd top by the top item
 * @head: the head of the  stack
 * @counter: code line position
 * Return: nothing
 */
void stack_mod(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int sm_len = 0, result;

	h = *head;

	while (h)
	{
		h = h->next;
		sm_len++;
	}

	if (sm_len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(store.file);
		free(store.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;

	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(store.file);
		free(store.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	result = h->next->n % h->n;
	h->next->n = result;
	*head = h->next;
	free(h);
}
