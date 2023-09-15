int get_input(t_ls **head, char *str)
{
	char **tmp;
	int i;

	i = 0;
	tmp = ft_split(str, ' ');
	if (!tmp)
		return (0);
	while (tmp[i] != NULL)
	{
		if (!check_chr(tmp[i]))
		{
			ft_free_all();
			return (0);
		}
		if (!ft_atoi_callback(head, tmp[i], ft_new_addback_int))
		{
			ft_free_all();
			return (0);
		}
		i++;
	}
	i = unvalid_in(*head);
	if (i)
	{
		ft_free_all();
		if (i == 1)
			printf("Error\n");
		return (0);
	}
	return (1);
}

int check_chr(const char *s)
{
	int i;
	while (s[i])
	{
		if (!((s[i] >= '0' && s[i] <= '9') || s[i] == '-' || s[i] == '+'))
			return (0);
		i++;
	}
	return (1);
}

void ft_new_addback_int(t_ls **head, int value)
{
	t_ls *new;

	new = (t_ls *)malloc(sizeof(t_ls));
	new->value = value;
	new->next = next;
	ft_lstadd_back(*head, value);
}
