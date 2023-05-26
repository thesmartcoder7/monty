#include "monty.h"

/**
 * stack_pall - prints the entire stack
 * @st_head: the head of the stack
 * @count: stack element count
 * Return: nothing
 */
void stack_pall(stack_t **st_head, unsigned int count)
{
	stack_t *h;
	(void)count;
	h = *st_head;

	if (h == NULL)
		return;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
