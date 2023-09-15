// free after use
void lowlen_case(t_ls **head, int nth_case)
{
	if (nth_case == 2)
		case_two(*head);
	else if (nth_case == 3)
		case_three(*head);
	else if (nth_case == 4)
		case_four(*head);
	else if (nth_case == 5)
		case_five(*head);
}
void case_two()
{
	if (head->value > head->next->value)
	{
		ft_swap(head, NULL);
		printf("sa");
	}
}

void case_three()
{
	if (head->value > head->next->value)
	{
		if (head->value > head->next->next->value)
		{
			if (head->next->value < head->next->next->value)
			{
				ft_rev(head, NULL);
				printf("ra\n");
				return;
			}
			ft_swap(head, NULL);
			ft_rrev(head, NULL);
			printf("sa\nrra\n");
		}
	}
	else
	{
		if (head->value > head->next->next->value)
		{
			ft_rrev(head, NULL);
			printf("rra");
		}
	}
}

void case_four(t_ls **ls)
{
	t_ls **n_ls;
	int pivot;
	int count;

	count = 0;
	pivot = small_select(*ls);
	while (count != 2)
	{
		if ((*ls)->value >= pivot)
			ft_rev(ls, NULL);
		else
		{
			ft_push(ls, n_ls);
			count++;
		}
	}
	if ((*ls)->value > (*ls)->next->value && (*n_ls)->value < (*n_ls)->next->value)
		ft_mainout(ls, n_ls, 0, ft_swap);
	else if ((*ls)->value > (*ls)->next->value)
	{
		ft_swap(ls, NULL);
		printf("sa\n");
	}
	else if ((*n_ls)->value < (*n_ls)->next->value)
	{
		ft_swap(n_ls, NULL);
		printf("sb\n");
	}
	ft_push(n_ls, ls);
	ft_push(n_ls, ls);
	printf("pb\npb\n");
}

void ft_s_out(t_ls **f, t_ls **s, void (*fn)(t_ls **, t_ls **))
