#include "push_swap.h"

void manda_sort(t_ls **head, int a_pivot, t_ls **to_free)
{
	t_ls *b_head;
	t_ls	*temp;

	ft_free_list(to_free);
	get_order(*head);
	write(1,"\naf_order\n", 10);
	b_head = init_sort(head, a_pivot);
	sorting(head, &b_head);
	temp = *head;
	while (temp)
	{
		write(1,"\n++++", 5);
		write(1, ft_itoa(temp -> value), 1);
		write(1,"++++\n", 5);
		temp = temp -> next;
	}
	ft_free_list(head);
	b_head = NULL;
}

t_ls	*init_sort(t_ls **a_head, int a_pivot)
{
	t_ls *a_tail;
	t_ls *b_head;
	t_ls *b_tail;
	int	count;

	if (a_pivot)
		;
	b_head = NULL;
	a_tail = ft_lstlast(*a_head);
	b_tail = NULL;
	count = lst_len(*a_head) / 2;
	if (lst_len(*a_head) % 2 == 1)
		count++;
	while (count)
	{
		if ((*a_head)-> value < a_pivot)
		{
			ft_push(a_head, &b_head, &b_tail);
			write(1,"pa\n", 3);
			count--;
		}
		else
			ft_si_out(a_head, &a_tail, 'a', ft_rev);
	}
	write(1, "\nendloop\n",9);
	t_ls *temp = *a_head;
	while (temp)
	{
		write(1,"\n++++", 5);
		write(1, ft_itoa(temp -> value), 1);
		write(1,"++++\n", 5);
		temp = temp -> next;
	}
		write(1,"\n++++", 5);
		write(1,"\n++++", 5);
		write(1,"\n++++", 5);
	temp = b_head;
	while (temp)
	{
		write(1,"\n++++", 5);
		write(1, ft_itoa(temp -> value), 1);
		write(1,"++++\n", 5);
		temp = temp -> next;
	}
	return (b_head);
}

