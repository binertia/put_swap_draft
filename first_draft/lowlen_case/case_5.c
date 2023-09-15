void case_five(t_ls **a_head)
{
	t_ls *b_head;
	int low_pivot;
	int pivot;

	b_head = NULL;
	pivot = small_select(a_head);
	while (a_head->next->next->next)
		ft_push(&a_head, &b_head);
	printf("pa\npa\n");
	low_pivot = lower_pivot(a_head);
	if (low_pivot == 1)
	{
		if (eq_pivot(a_head, pivot))
			ccase_1_piv(&a_head, &b_head);
		else
			ccase_1(&a_head, &b_head);
	}
	else if (low_pivot == 2)
		ccase_2(&a_head, &b_head);
	else
		ccase_3(&a_head, &b_head);
}

void ccase_1(t_ls **a_head, t_ls **b_head)
{
	if ((*a_head)->value < (*a_head)->next->value)
	{
		if ((*a_head)->next->value < (*a_head)->next->next->value)
			ft_mainout(a_head, b_head, 0, ft_rev);
		else if ((*a_head)->value < (*a_head)->next->next->value)
		{
			ft_mainout(a_head, b_head, 0, ft_rev)
			ft_si_out(a_head, NULL, 'a', ft_swap);
		}
	}
	else
	{
		if ((*a_head)->next->value > (*a_head)->next->next->value)
			ft_mainout(a_head, b_head, 0, ft_swap);
		else
		{
			if ((*a_head->value > (*a_head)->next->next->value))
				ft_mainout(a_head, b_head, 0, ft_rrev);
			else
			{
				ft_mainout(a_head, b_head, 0, ft_swap);
				ft_si_out(a_head, NULL, 'a', ft_rrev);
			}
		}
	}
}

void ccase_1_piv(t_ls **a_head, t_ls **b_head)
{
	t_ls *head;

	head = *a_head;
	if (head->value > head->next->value)
	{
		if (head->value > head->next->next->value)
		{
			if (head->next->value < head->next->next->value)
				ft_mainout(a_head, b_head, 0, ft_rev);
			else
			{
				ft_si_out(a_head, NULL, 'a', ft_swap);
				ft_mainout(a_head, b_head, 0, ft_rrev);
			}
		}
		else
			ft_mainout(a_head, b_head, 0, ft_swap);
	}
	else if (head->value > head->next->next->value)
		ft_mainout(a_head, b_head, 0, ft_rrev)
}

void ccase_2(t_ls **a, t_ls **b)
{
	temp = *a;
	if (temp->value < temp->next->value)
	{
		if (temp->next->value < temp->next->next->value)
			ft_mainout(a, b, 0, ft_rrev);
		else
		{
			if (temp->value < temp->next->next->value)
				ft_mainout(a, b, 0, ft_swap) else ft_mainout(a, b, 0, ft_rev)
		}
	}
	else
	{
		if (temp->value < temp->next->next->value)
		{
			ft_mainout(a, b, 0, ft_swap);
			ft_si_out(a, NULL, 'a', ft_rrev);
		}
		else if (temp->next->value > temp->next->next->value)
		{
			ft_mainout(a, b, 0, ft_swap)
			ft_si_out(a, NULL, 'a', ft_rev);
		}
	}
	ccase_2_extend(a, b);
}

void ccase_2_extend(t_ls **a_head, t_ls **b_head)
{
	int lowth_piv;
	t_ls *temp;

	i = 0;
	temp = *a_head;
	while (temp)
	{
		if (temp->value < b_head->value)
			lowth_piv++;
	}
	ft_push(b_head, a_head);
	printf("pb\n");
	if (lowth_piv == 2)
	{
		ft_push(b_head, a_head);
		printf("pb\n");
		ft_si_out(b_head, NULL, 'b', ft_rev);
	}
	ft_si_out(a_head, NULL, 'a', ft_rev);
	ft_si_out(a_head, NULL, 'a', ft_rev);
	if (lowth_piv != 2)
	{
		ft_push(b_head, a_head);
		printf("pb\n");
	}
	if (a_head->value > a_head->next->value)
		ft_si_out(a_head, NULL, 'a', ft_swap);
}

void ccase_3(&a_head, &b_head)
{
	if ((*a_head)->value > (*a_head)->next->value)
	{
		if ((*a_head)->value > (*a_head)->next->next->value)
		{
			if ((*a_head)->next->value < (*a_head)->next->value)
				ft_mainout(a_head, b_head, 1, ft_rev);
			else
			{
				ft_mainout(a_head, b_head, 1, ft_swap);
				ft_si_out(a_head, NULL, 'a', ft_rrev);
			}
		}
		else
			ft_mainout(a_head, b_head, 1, ft_swap);
	}
	else
	{
		if ((*a_head)->value < (*a_head)->next->next->value)
		{
			ft_mainout(a_head, b_head, 1, ft_swap);
			ft_si_out(a_head, NULL, 'a', ft_rev);
		}
		else if ((*a_head)->value > (*a_head)->next->next->value)
			ft_mainout(a_head, b_head, 1, ft_rrev);
	}
	ccase_3_extend(a_head, b_head);
}

void ccase_3_extend(t_ls **a_head, t_ls **b_head)
{
	if ((*b_head)->value < (*b_head)->next->value)
		ft_si_out(b_head, NULL, 'b', ft_swap);
	ft_push(b_head, a_head)
	ft_push(b_head, a_head)
	printf("pb\npb\n")
}
