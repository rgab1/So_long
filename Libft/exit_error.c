#include <libft.h>

void	exit_error(char *error_msg, int error_code)
{
	puterror(error_msg);
	exit(error_code);
}
