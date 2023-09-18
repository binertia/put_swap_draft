#include "push_swap.h"

/*
static int	get_max_bit(t_ls *ls)
{
	int	bit;
	int	num;

	num = ls -> order;
	bit = 0;
	write(1, "\n get max bit \n", 14);
	while (ls)
	{
		if (ls -> order > num)
			num = ls -> order;
		ls = ls -> next;
	}
	while ((num >> bit) != 0)
		bit++;
	write(1, "\n((",3);
	write(1, ft_itoa(bit), 1);
	write(1, "))\n",3);
	return (bit);
}

static int	gas_station(t_ls **a, int bit, int is_ascen)
{
	int	count;
	t_ls *temp;

	count = 0;
	temp = *a;
	while (temp)
	{
		if (((temp -> order >> bit)  & 1 ) == is_ascen)
			temp -> gas = 0;
		else
		{
			write(1,"\nadd gas\n", 9);
			temp -> gas = 1;
			count++;
		}
		temp = temp -> next;
	}
	return (count);
}

static int	god_of_loop(t_ls **s, t_ls **d, char c, int i)
{
	t_ls	*d_tail;
	t_ls	*s_tail;

	d_tail = ft_lstlast(*d);
	s_tail = ft_lstlast(*s);
	write(1, ft_itoa((*s) -> value), 1);
	write(1, " gas : ", 7);
	write(1, ft_itoa(i), 1);
	write(1, ft_itoa((*s) -> gas), 1);
	if ((*s) -> gas == 1)
	{
		(*s) -> gas = 0;
		ft_push(s, d, &d_tail);
		write(1, "p", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
		return (1);
	}
	else
		ft_si_out(s, &s_tail, c, ft_rev);
	write(1, ft_itoa((*s) -> value), 1);
	write(1," godlop ", 8);
	return (0);
}
int	is_finish(t_ls *s)
{
	while (s && s -> value < s -> next -> value)
		s = s -> next;
	if (!(s -> next))
		return (1);
	return (0);
}

static void	god_of_sorting(t_ls **s, t_ls **d, int is_ascen, char c)
{
	int	bit;
	int	count_p;
	int	max_bit;
	int	i;
	t_ls	*tail;

	tail = ft_lstlast(*s);
	bit = 0;
	max_bit = get_max_bit(*s);
	while (bit < max_bit && !is_finish(*s))
	{
		count_p = gas_station(s, bit, is_ascen);
		i = count_p;
		while (i)
			i -= god_of_loop(s, d, c, i);
		while (count_p--)
			ft_push(d, s, &tail);
		bit++;
	}
	write(1,"end sort\n", 11);
	t_ls *temp = *s;
	while (temp)
	{
		write(1,"\n++++", 5);
		write(1, ft_itoa(temp -> value), 1);
		write(1,"\n++:++", 5);
		write(1, ft_itoa(temp -> order), 1);
		write(1,"++++\n", 5);
		temp = temp -> next;
	}
}
*/
/*
int	get_max_bit(t_ls *s)
{
	int	bit;
	int	num;

	bit = 0;
	num = s -> order;
	while (s)
	{
		if (s -> order >num)
			num = s -> order;
		s = s -> next;
	}
	if ((num >> bit) != 0)
		bit++;
	return (bit);
}

void	radix(t_ls **s, t_ls **b, t_ls *temp, int len)
{
	t_ls	*a_tail;
	int	bit;
	int	i;
	int	j;
	int	max_bit;

	bit = 0;
	max_bit = get_max_bit(*s);
	while(bit < max_bit)
	{
		i = 0;
		j = 0;
		while (i++ < len)
		{
			write(1, " loop ", 6);
			if (((temp -> order >> bit) & 1) == 1)
			{
				ft_si_out(s, &a_tail, 'a', ft_rev);
			}
			else
			{
				write(1, "pb\n", 3);
				ft_push(s, b, &a_tail);
				j++;
			}
			while (j)
			{
				write(1, "__pb\n", 3);
				ft_push(b, s, &a_tail);
				j--;
			}
		}
		bit++;
	}
}
*/

int	is_finish(t_ls *s)
{
	while (s && s -> value < s -> next -> value)
		s = s -> next;
	if (!(s -> next))
		return (1);
	return (0);
}

void	radix(t_ls **a, t_ls**b)
{
	int	a_len;
	int	b_len;
	int	bit;
	t_ls	*a_tail;

	a_tail = ft_lstlast(*a);
	bit = 1;
	while (!is_finish(*a))
	{
		a_len = lst_len(*a);
		while (a_len--)
		{
			if ((*a) -> order & bit)
				ft_si_out(a, &a_tail, 'a', ft_rev);
			else
				ft_push(a, b, &a_tail);
		}
		b_len = lst_len(*b);
		while(b_len--)
			ft_push(b, a, &a_tail);
		bit <<= 1;
	}
}

void	sorting(t_ls **a, t_ls **b)
{
	t_ls	*test;
	t_ls	*a_tail;

	a_tail = ft_lstlast(*a);
	while (*b)
		ft_push(b, a, &a_tail);
	radix(a, b);
	//god_of_sorting(a, b, 1, 'a');
	write(1,"\nend god sort\n", 14);
	test = *a;
	while (test)
	{
		write(1, "\n==",3);
		write(1, ft_itoa(test -> value), 2);
		write(1, "==\n",3);
		test = test -> next;
	}
	//god_of_sorting(b, a, 0, 'b');
	write(1,"\nend god sort\n", 14);
	p_back(b, a);
}
