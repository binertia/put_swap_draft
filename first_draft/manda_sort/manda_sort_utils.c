void	ft_swap(t_ls **head, t_ls **tail)
{
	int	temp;
	t_ls	*dump;

	dump = tail;
	temp = (*head) -> value;
	(*head) -> value = (*head) -> next -> value;
	(*head) -> next -> value = temp;
}

void ft_rev(t_ls **head, t_ls **tail)
{
	*tail = *head;
	*head = (*head)->next;
	(*tail->next) = NULL;
}

void ft_rrev(t_ls **head, t_ls **tail)
{
	t_ls *temp_a;
	t_ls *temp_b;

	temp_a = *head;
	while (temp_a->next->next != NULL)
		temp_a = temp_a->next;
	*tail = temp_a;
	temp_a = temp_a->next;
	temp_b = *head;
	*head = temp_a;
	*head->next = temp_b;
}

void	ft_push(t_ls **src, t_ls **dst, t_ls **dst_tail)
{
	t_ls	temp;

	temp = *src;
	*src = (*src) -> next;
	temp -> next = *dst;
	*dst = temp;
	if (!*dst_tail)
		*des_tail = *des;
}
