void	ft_si_out(*t_ls **f,*t_ls **t, char c, void (*fn)(t_ls **, t_ls **))
{
	void	(*swap)(t_ls **, t_ls **);
	void	(*rev)(t_ls **, t_ls **);
	void	(*rrev)(t_ls **, t_ls **);

	swap = ft_swap;
	rev = ft_rev;
	rrev = ft_rrev;
	fn(f, t);
	if (fn == swap)
		printf("s");
	else if (fn == rev)
		printf("r");
	else if (fn == rrev)
		printf("rr");
	if (c == 'a')
		printf("a\n");
	else
		printf("b\n");
}
