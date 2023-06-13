/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:34:07 by gcastro-          #+#    #+#             */
/*   Updated: 2023/06/06 18:34:09 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_boolean	is_file(char *file);

int	error(char *message)
{
	ft_printf ("ERROR\n%s\n", message);
	return (0);
}

void	cmd_error(char *cmd)
{
	char	*err_message;

	err_message = ft_strjoin (cmd, "COMMAND NOT FOUND\n");
	error (err_message);
	free (err_message);
}

t_boolean	error_checker(int argc, char **argv)
{
	char	*err_message;

	err_message = NULL;
	if (argc < 5)
		return (error ("MISSING ARGS"));
	if (!is_file (argv[1]))
		return (FALSE);
	if (access(argv[1], R_OK) != 0)
	{
		err_message = ft_strjoin(argv[1], " DOESN'T HAVE PERMISSIONS ENABLED");
		error (err_message);
		free(err_message);
		return (FALSE);
	}
	
	return (TRUE);
}
