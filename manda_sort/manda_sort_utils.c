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
