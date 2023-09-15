void ft_new_addback_int(t_ls **head, int value)
{
	t_ls *new;

	new = (t_ls *)malloc(sizeof(t_ilst));
	new->value = value;
	new->next = next;
	ft_lstadd_back(*head, value)
}

t_ls *ft_lstdup(t_ls *src)
{
	t_ls *head;
	t_ls *current;
	t_ls *tmp;

	if (!src)
		return (0);
	current = src;
	while (!current)
	{
		ft_new_addback_int(&head, current->value) // need handle malloc err
				current = current->next;
	}
	return (head);
}
