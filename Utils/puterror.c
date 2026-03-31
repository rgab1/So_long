#include <libft.h>

void	puterror(char *s, int error_code)
{
	if (!s)
		return ;
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(s, 2);
	exit(error_code);
}
