int main(int ac, char **av)
{
	int i;
	int a_pivot;
	int b_pivot;
	t_ls *head;
	t_ls *tmp;

	head = NULL;
	if (ac < 2)
		return (exit);
	i = 1;
	while (++i != ac)
	{
		if (!get_input(&head, av[i]))
			return (0);
		i++;
	}
	i = lst_len(head);
	if (i < 6)
	{
		lowlen_case(&head, i);
		return (0);
	}
	i = (i / 2);
	tmp = ft_lstdup(head); // need to handle if malloc failed
	b_pivot = quick_select_n(tmp, i + 1);
	a_pivot = quick_select_n(tmp, i);
	ft_free_lst(&tmp);
	manda_sort(head, a_pivot, b_pivot); // need
	ft_free();													// need
	return (0);
}
