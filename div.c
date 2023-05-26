#include "monty.h"
/**
 * stack_div - this divides the top two elements of the stack.
 * @head: the head of the stack
 * @counter: code line position
 * Return: nothing
 */
void stack_div(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int sm_len = 0, temp_store;

	h = *head;
	while (h)
	{
		h = h->next;
		sm_len++;
	}
	if (sm_len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
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
	temp_store = h->next->n / h->n;
	h->next->n = temp_store;
	*head = h->next;
	free(h);
}
