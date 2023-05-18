
#include "pipex.h"

int error(char *message)
{
	ft_printf("ERROR\n%s\n", message);
	return (0);
}

void	*null_error(char **message)
{
	ft_printf("ERROR\n%s\n", message);
	return (NULL);
}

t_boolean is_file(char *file)
{
	int			fd;
	t_boolean	checker;
	char		*err_message;

	checker = TRUE;
	err_message = ft_strjoin(file, " FILE DON'T EXIST");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		checker = error(err_message);
	close(fd);
	free(err_message);
	return (checker);
}

/**
 * This fuction is dedicated to detect <b>basics errors</b>
 * that it can be found in the run time init.
 * Errors:
 * - Invalid args number.
 * - Invalid args format.
 * 
 * @param <b>ARGC.</b> El número de argumentos pasados al programa
 * @param <b>ARGV.</b> Una matriz con los argumentos pasados al programa
 * @return	TRUE si no encuentra ningún error,
 * 			FALSE si encuentra alguno de los errores mencionados
*/
t_boolean error_checker(int argc, char **argv)
{
	if (argc < 5)
		return (error("MISSING ARGS"));
	if (!is_file(argv[1]) || !is_file(argv[argc - 1]))
		return (FALSE);
	return (TRUE);
}
