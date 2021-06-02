#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
* find_listint_loop - Finds loop in linked list.
* @head: head of list.
* Return:
*   Null - if there is no loop
*   or Address of node where the loop starts.
*/

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tmp_quick, *tmp_slow;

	if (head == NULL)
	{
		return (NULL);
	}

	while (tmp_quick->next != NULL && tmp_quick->next->next != NULL)
	{
		tmp_slow = tmp_slow->next;
		tmp_quick = tmp_quick->next->next;

		if (tmp_slow == tmp_quick)
		{
			tmp_slow = head;
			while (tmp_slow != tmp_quick)
			{
				tmp_slow = tmp_slow->next;
				tmp_quick = tmp_quick->next;
			}
			return (tmp_quick);
		}
	}
	return (NULL);
}
