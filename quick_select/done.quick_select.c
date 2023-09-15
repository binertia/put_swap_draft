static t_ls *partition(t_ls *low, t_ls *high)
{
	int pivot;
	t_ls i;
	t_ls j;

	pivot = low->value;
	i = low;
	j = low->next;
	while (j != high)
	{
		if (j->value < pivot)
		{
			i = i->next;
			swap(&(i->value), &(j->value))
		}
		j = j->next;
	}
}

t_ls quickselect_n(t_ls *head, int n)
{
	t_ls *t_pivot;
	t_ls *current;
	int pos_pivot;

	if (!head)
		return (NULL);
	t_pivot = partition(head, NULL);
	pos_pivot = 0;
	current = head;
	while (current != t_pivot)
	{
		pos_pivot++;
		current = current->next;
	}
	if (pos_pivot == n)
		return (t_pivot);
	else if (pos_pivot < n)
		return (quickselec_nth(t_pivot->next, n - pos_pivot - 1));
	else
		return (NULL);
}
