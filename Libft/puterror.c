#include <libft.h>

void	puterror(char *error_msg)
{
	if (!error_msg)
		return ;
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_msg, 2);
}
