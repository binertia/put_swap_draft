// need to fix this function
void get_work(t_ls **list, t_ls **work, t_ls **tail, int pivot)
{
	t_ls *temp;

	temp = *list;
	if (temp->value == pivot)
	{
		// move to another function below
		temp = temp->next;
		while (temp->value > temp->next->value && temp->value > pivot)
			temp = temp->next;
		if (!temp)
		{
			ft_int_addback(work, 5);
			return;
		}
		temp = *list;
		temp = temp->next;
		while (temp->value < temp->next->value && temp->value < pivot)
			temp = temp->next;
		if (!temp)
		{
			ft_int_addback(work, 5);
			return;
		}
		temp = *list;
		/// move to another function
	}
	if (temp->value)
	{
	}
}

// swap = 1;
// rev = 2;
// rrev = 3;

get_work_a()
{
	if (temp->value < temp->next->value)
	{
		if (temp->value < tail->value && temp->next->value > tail->value)
		{
			ft_rrev(head, tail);
			ft_swap(head, tail);
			ft_int_addback(work, 3);
			ft_int_addback(work, 1);
		}
		ft_rev(head, tail);
		ft_int_addback(work, 2);
	}
	else
	{
		if (temp->next->value < tail->value)
			ft_rev();
		ft_int_addback(work, 2);
		else ft_sa();
		ft_int_addback(work, 1);
	}
}
get_work_b()
{
	if (temp->value > temp->next->value)
	{
		if (temp->value > tail->value && temp->next->value < tail->value)
		{
			ft_rrev(head, tail);
			ft_swap(head, tail);
			ft_int_addback(work, 3);
			ft_int_addback(work, 1);
		}
		ft_rev(head, tail);
		ft_int_addback(work, 2);
	}
	else
	{
		if (temp->next->value > tail->value)
			ft_rev();
		ft_int_addback(work, 2);
		else ft_swap();
		ft_int_addback(work, 1);
	}
}

void do_work(t_ls **work)
{
}

void do_work_both(t_ls **a_work, t_ls **b_work)
{
	do_work(a_work);
	do_work(b_work);
}
