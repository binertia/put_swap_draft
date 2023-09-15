#include <stdlib.h>
#include <stdio.h>

int is_space(const char *s)
{
	if ((*s >= '\t' && *s <= '\r') || *s == ' ')
		return (1);
	return (0);
}

int ft_atoi_callback(t_ls **head, const char *str, void (*fn)(t_ls **, int))
{
	int n_or_p;
	int result;
	int is_error;

	n_or_p = 1;
	result = 0;
	is_error = 0;
	while (is_space(str))
		str++;
	if (*str == '-')
		n_or_p = -1;
	if (*str == '-' || *str == '+')
		str++;
	if (*str < '0' || *str > '9')
		is_error = 1;
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + *str++ - '0';
	if (*str)
		is_error = 1;
	if (is_error)
	{
		ft_free_all()
				printf("Error");
		return (0);
	}
	else
		fn(head, result * n_or_p);
	return (1);
}

void add_data(t_ls **head, int num)
{
		fn(head , num));
}

int main(int ac, char *av[])
{
		if (ac == 2)
			printf("%d", ft_atoi(av[1]));
		return (0);
}
