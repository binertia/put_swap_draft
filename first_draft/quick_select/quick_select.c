static t_ls *get_parti(t_ls *low, t_ls *high)
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
			quick_swap_int(&(i->value), &(j->value))
		}
		j = j->next;
	}
}

t_ls quickselect_n(t_ls *head, int n)
{
	t_ls *t_piv;
	t_ls *current;
	int pos_piv;

	if (!head)
		return (NULL);
	t_piv = get_parti(head, NULL);
	pos_piv = 0;
	current = head;
	while (current != t_piv)
	{
		pos_piv++;
		current = current->next;
	}
	if (pos_piv == n)
		return (t_piv);
	else if (pos_piv < n)
		return (quickselec_nth(t_piv->next, (n - pos_piv - 1)));
	else
		return (NULL);
}
