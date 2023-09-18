#include "push_swap.h"

int eq_pivot(t_ls *head, int pivot)
{
	while (head)
	{
		if (head->value == pivot)
			return (1);
		head = head->next;
	}
	return (0);
}

int small_select(t_ls *head)
{
	t_ls *temp;
	t_ls *pivot;
	int count;

	count = 0;
	temp = head;
	pivot = head;
	while (pivot)
	{
		while (temp)
		{
			if (temp -> value < pivot -> value)
				count++;
			temp = temp -> next;
		}
		if (count == 2)
			return (pivot -> value);
		count = 0;
		temp = head;
		pivot = pivot -> next;
	}
	return (0);
}
