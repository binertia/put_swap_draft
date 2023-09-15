
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

	while (pivot)
	{
		temp = head;
		while (temp)
		{
			if (temp->value < pivot->value)
				count++;
			temp = temp->next;
		}
		if (count == 2)
			return (pivot->value);
		pivot = pivot->next;
	}
}
