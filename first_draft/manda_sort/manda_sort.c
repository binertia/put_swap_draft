// need to do unit test for all case . read check first . do push();
void manda_sort(t_ls *head, int a_pivot, int b_pivot)
{
	t_ls *b_head;

	b_head = init_sort(&a_head, b_pivot);
	full_sort(&a_head, &b_head, a_pivot, b_pivot);
	free_all(a_head);
	a_head = NULL;
	b_head = NULL;
}

// how to do manda_sort
//
// 1
// init_sort

t_ls	*init_sort(t_ls **a_head, int b_pivot)
{
	t_ls *a_tail;
	t_ls *b_head;
	t_ls *b_tail;
	int	count;

	b_head = NULL;
	a_tail = NULL;
	b_tail = NULL;
	count = lst_len(*a_head) / 2;
	init_tail(*a_head, &a_tail, &b_tail);
	while (count)
	{
		if ((*a_head)->value < b_pivot)
		{
			ft_push(*a_head, &b_head, &b_tail);
			count--;
		}
		else if ((*a_head) -> value < (*a_head) -> next -> value)
			init_sort_swapk(a_head, &a_tail, &b_head, &b_tail);
		else
			init_sort_rev(a_head, &a_tail, &b_head, &b_tail);
	}
	return (b_head);
}

void	init_sort_swap(t_ls **a_head, t_ls **a_tail, t_ls **b_head, **b_tail)
{
	ft_swap(a_head, a_tail);
	if (*b_head && (*b_head) -> next != NULL && (*b_head) -> value < (*b_head) -> next -> value 
			&& (*b_head) -> next != *b_tail)
	{
		ft_swap(b_head, b_tail);
		printf("ss");
	}
	else
		printf("sa");
}

void	init_sort_rev(t_ls **a_head, t_ls **a_tail, t_ls **b_head, **b_tail)
{
	ft_rev(a_head, a_tail);
	if (*b_head && ((*b_head) -> next != NULL) && (*b_head) -> value > (*b_head) -> next -> value 
			&& (*b_head) -> next != *b_tail)
	{
		ft_rev(b_head, b_tail);
		printf("rs");
	}
	else
	{
		printf("rs");
	}
}


void init_tail(t_ls *a_head, t_ls **a_tail, t_ls **b_tail)
{
	while (a_head->next != NULL)
		a_head = a_head->next;
	*a_tail = a_head;
	*b_tail = NULL;
}

// void	update_tail(t_ls *head)
{
}

int get_len(t_ls *a_head, t_ls *b_head)
{
	int i;

	while (a_head)
	{
		a_head = a_head->next;
		i++;
	}
	while (b_head)
	{
		b_head = b_head->next;
		i++;
	}
	return (i);
}

void full_sort(t_ls **a_head, t_ls **b_head, int a_pivot, t_ls b_pivot)
{
	t_ls *a_work;
	t_ls *b_work;
	int fin;

	fin = 0;
	a_work = NULL;
	b_work = NULL;
	while (!fin)
	{
		get_work_a(a_head, &a_work, a_pivot);
		while (!fin && !(b_work && b_work->next))
		{
			get_work_b(b_head, &b_work, b_pivot);
			fin = check_fin(a_work, b_work, fin);
		}
		full_sort_dowork(&a_work, &b_work, fin);
	}
	fin = check_fin(a_work, b_work, fin);
	if (fin == 1)
		full_sort_fin(b_head, &b_work, b_pivot, &b_head);
	else if (fin == 2)
		full_sort_fin(a_head, &a_work, a_pivot, &b_head);
}

void	full_sort_dowork(t_ls **a_work, t_ls **b_work, int fin)
{
	while (!fin && *b_work && *a_work && (*b_work) -> next)
	{
		if ((*a_work) -> value != (*b_work) -> value)
		{
			if ((*a_work) -> value == (*b_work) -> next -> value)
				do_work(b_work);
			else
				do_work(a_work);
		}
		else
			do_work_both(a_work, b_work);
	}
}

void	full_sort_fin(t_ls **head, t_ls **work, int pivot)
{
	while (1)
	{
	
			while (!(*work && (*work) -> next))
				*work = get_work_b(head, work, pivot);
			if ((*work) -> value == 5)
				return ;
			while (*work)
				do_work(work);
	}

}

int	check_fin(t_ls *a_work, t_ls *b_work, fin)
{
	while (a_work && fin != 1)
	{
		if (a_work->value == 5)
		{
			if (fin == 2)
				return (3);
			return (1);
		}
		a_work = a_work->next;
	}
	while (b_work && fin != 2)
	{
		if (b_work->value == 5)
		{
			if (fin == 1)
				return (3);
			return (2);
		}
		b_work = b_work->next;
	}
	return (0);
}
