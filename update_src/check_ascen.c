#include "push_swap.h"

int	check_ascen(t_ls **head)
{
	t_ls	*temp;

	write(1,"\nstart ascen\n", 12);
	temp = *head;
	if (!(temp -> next))
		return (0);
	while (temp -> next && temp -> value < temp -> next -> value)
	{
	write(1,"\nin ascen\n", 9);
		temp = temp -> next;
	}
	if (!(temp -> next))
	{
		write(1,"\nexit ascen\n", 9);
		ft_free_list(head);
		return (1);
	}
	return (0);
}
