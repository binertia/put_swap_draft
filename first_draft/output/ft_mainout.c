void ft_mainout(t_ls **a_l, t_ls **b_l, int num, void (*fn)(t_ls **, t_ls **))
{
	void (*swap)(t_ls **, t_ls **) = ft_swap;
	void (*rev)(t_ls **, t_ls **) = ft_rev;
	void (*rrev)(t_ls **, t_ls **) = ft_rrev;
	int is_swap;

	is_swap = 0;
	fn(a_l, NULL);
	is_swap = b_swap(b_head, num);
	if (fn == swap)
		printf("s");
	else if (fn == rev)
		printf("r");
	else if (fn == rrev)
		printf("rr");
	if (is_swap)
		printf("s\n");
	else
		printf("a\n");
}

int b_swap(t_ls **head, int incre)
{
	if (incre)
		return (swap_incre(head));
	else
		return (swap_decre(head));
}

void swap_incre(t_ls **head)
{
	if (head->value > head->next->value)
	{
		ft_swap(head, NULL);
		return (1);
	}
	return (0);
}

void swap_decre(t_ls **head)
{
	if (head->value < head->next->value)
	{
		ft_swap(head, NULL);
		return (1);
	}
	return (0);
}
