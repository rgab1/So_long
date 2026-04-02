size_t	ft_tablen(void **tab)
{
	size_t	count;

	count = 0;
	while (*tab)
	{
		tab++;
		count++;
	}
	return (count);
}
