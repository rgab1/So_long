#include <libft.h>

size_t	ft_tablen(void **tab)
{
	size_t	count;

	if (!tab)
		return (0);
	count = 0;
	while (*tab)
	{
		tab++;
		count++;
	}
	return (count);
}
