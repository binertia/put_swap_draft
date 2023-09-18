#include "push_swap.h"

void	ft_swap(t_ls **head, t_ls **tail)
{
	int		temp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	*tail = ft_lstlast(*head);
	temp = (*head) -> value;
	(*head) -> value = (*head) -> next -> value;
	(*head) -> next -> value = temp;
}

void ft_rev(t_ls **head, t_ls **tail)
{
	t_ls	*temp;

	*tail = ft_lstlast(*head);
	temp = *head;
	*head = (*head) -> next;
	(*tail) -> next = temp;
	temp -> next = NULL;
	*tail = temp;
	temp = *head;
}

void ft_rrev(t_ls **head, t_ls **tail)
{
	t_ls *temp_a;

	*tail = ft_lstlast(*head);
	temp_a = *head;
	while (temp_a->next->next != NULL)
		temp_a = temp_a->next;
	*tail = temp_a;
	temp_a = temp_a->next;
	(*tail) ->next = NULL;
	temp_a -> next = *head;
	*head = temp_a;
	//
	
	//tmp = *head;
	//*head = *tail;
	//(*head) -> next = tmp;
}

void	ft_push(t_ls **src, t_ls **dst, t_ls **dst_tail)
{
	t_ls	*temp;

	temp = *src;
	*src = (*src) -> next;
	temp -> next = *dst;
	*dst = temp;
	*dst_tail = ft_lstlast(*dst);
}
