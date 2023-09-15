// free after use
void lowlen_case(t_ls **head, int nth_case)
{
	if (nth_case == 2)
		case_two(head);
	else if (nth_case == 3)
		case_three(head);
	else if (nth_case == 4)
		case_four(head);
	else if (nth_case == 5)
		case_five(head);
	ft_free_all(head);
}

void case_two(t_ls **head)
{
	if (head->value > head->next->value)
		ft_si_out(head, 'a', ft_swap);
}

void case_three(t_ls **head)
{
	if (head->value > head->next->value)
	{
		if (head->value > head->next->next->value)
		{
			if (head->next->value < head->next->next->value)
			{
				ft_si_out(head, 'a', ft_rev);
				return;
			}
			ft_si_out(head, 'a', ft_swap);
			ft_si_out(head, 'a', ft_rrev);
		}
	}
	else
	{
		if (head->value > head->next->next->value)
			ft_si_out(head, 'a', ft_rrev);
	}
}

void case_four(t_ls **ls)
{
	t_ls **n_ls;
	int pivot;
	int count;

	count = 0;
	n_ls = NULL;
	pivot = small_select(*ls);
	while (count != 2)
	{
		if ((*ls)->value >= pivot)
			fi_si_out(ls, 'a', ft_rev);
		else
		{
			ft_push(ls, n_ls);
			printf("pb\n");
			count++;
		}
	}
	if ((*ls)->value > (*ls)->next->value && (*n_ls)->value < (*n_ls)->next->value)
		ft_mainout(ls, n_ls, 0, ft_swap);
	else if ((*ls)->value > (*ls)->next->value)
		fi_si_out(ls, 'a', ft_swap);
	else if ((*n_ls)->value < (*n_ls)->next->value)
		fi_si_out(ls, 'b', ft_swap);
	ft_push(n_ls, ls);
	ft_push(n_ls, ls);
	printf("pb\npb\n");
}
