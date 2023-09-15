// int will be different || exit();

int unvalid_in(t_ls *head)
{
	t_ls *temp;

	temp = head->next;
	if (!temp)
		return (0);
	while (head)
	{
		while (temp)
		{
			if (head->value == temp->value)
				return (0);
			temp = temp->next;
		}
		head = head->next;
		temp = head->next;
	}
	return (2);
}
