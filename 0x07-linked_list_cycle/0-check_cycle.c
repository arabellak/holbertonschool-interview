#include "lists.h"

/**
 * check_cycle - Checks if a singly linked list has a cycle.
 * @list: list;
 * Return: 0 if there is no cycle or 1 if there is.
 */

int check_cycle(listint_t *list)
{
	listint_t *tmp_quick, *tmp_slow;

	tmp_slow = tmp_quick = list;

	while (tmp_slow && tmp_quick && tmp_quick->next)
	{
		tmp_slow = tmp_slow->next;
		tmp_quick = tmp_quick->next->next;

		if (tmp_slow == tmp_quick)
			return (1);
	}

	return (0);
}
