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
init_sort(*a_head, b_pivot)
{
	t_ls *a_tail;
	t_ls *b_head;
	t_ls *b_tail;
	t_ls *temp;
	int finish;

	finish = 0;
	temp = a_head;
	init_tail(a_head, &a_tail, &b_tail);
	while (!finish)
	{
		if (a_head->value < b_pivot)
			ft_push(a_head, b_head, &b_tail);
		else if (a_head->value < a_head->next->value)
		{
			ft_swap(&a_head, &a_tail);
			if (b_head && (b_head->next != NULL) && (b_head->value < b_head->next->value) && b_head->next != b_tail)
			{
				ft_swap(&b_head, &b_tail);
				printf("ss");
			}
			else
				printf("sa");
		}
		else
		{
			ft_rev(&a_head, &a_tail);
			if (b_head && (b_head->next != NULL) && b_head->value > b_head->next->value && b_head->next != b_tail)
			{
				ft_rev(&b_head, &b_tail);
				printf("rs");
			}
			else
			{
				printf("rs");
			}
		}
	}
	return (b_head);
}

void init_tail(t_ls *a_head, t_ls **a_tail, t_ls **b_tail)
{
	while (a_head->next != NULL)
		a_head = a_head->next;
	*a_tail = a_head;
	*b_tail = NULL;
}

ft_pa ft_push(t_ls **src, t_ls **des, t_ls **des_tail)
{
	t_ls temp;

	temp = *src;
	*src = (*src)->next;
	temp->next = *des;
	*des = temp;
	if (!*des_tail)
		*des_tail = *des;
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

void full_sort(t_ls *a_head, t_ls *b_head, int a_pivot, t_ls b_pivot)
{
	t_ls *a_work;
	t_ls *b_work;
	int fin;

	fin = 0;
	while (!fin)
		while (!(a_work && a_work->next))
			get_work_a(&a_head, &a_work, &a_tail, a_pivot);
	while (!(b_work && b_work->next))
		get_work_b(&b_head, &b_work, &b_tail, b_pivot);
	if (a_work || b_work)
		fin = check_fin(a_work, b_work, fin);
	if (fin)
	{
		fin = check_fin(a_work, b_work, fin) break;
	}
	while (!fin && b_work && a_work && b_work->next)
	{
		if (a_work->value != b_work->value)
		{
			if (a_work->value == b_work->next->value)
				do_work(&b_work);
			else
				do_work(&a_work);
		}
		else
			do_work_both(&a_work, &b_work);
	}
}
if (fin == 1)
{
	while (1)
	{
		while (!(b_work && b_work->next))
			b_work = get_work_b(&b_head, &b_work, b_pivot);
		if (b_work->value == 5)
			break;
		while (b_work)
			do_work(&b_work);
	}
}
else if (fin == 2)
{
	while (1)
	{
		while (!(a_work && a_work->next))
			a_work = get_work_a(&a_head, &a_work, a_pivot);
		if (a_work->value == 5)
			break;
		while (a_work)
			do_work(&a_work);
	}
}
while (b_work)
	ft_push(b_work, a_work, NULL);
}

int check_fin(t_ls *a_work, t_ls *b_work, fin)
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
