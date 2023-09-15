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
	int is_pos;
	int result;
	int is_error;

	is_pos = 1;
	result = 0;
	is_error = 0;
	while (is_space(str))
		str++;
	if (*str == '-')
		is_pos = -1;
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
		ft_free_all()      //  recheck this line
		printf("Error");
		return (0);
	}
	fn(head, (result * is_pos));
	return (1);
}
