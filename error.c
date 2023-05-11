
#include "pipex.h"

int error(char **message)
{
	ft_printf("ERROR\n%s", message);
	return (0);
}

void	*null_error(char **message)
{
	ft_printf("ERROR\n%s", message);
	return (NULL);
}

t_boolean error_checker()
{
	return (TRUE);
}
