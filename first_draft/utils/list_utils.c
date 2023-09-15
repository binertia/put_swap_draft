t_ls	*ft_lstdup(t_ls *src)
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


// need to make

void	ft_new_addfront_int(t_ls **head, int num)
{

}
