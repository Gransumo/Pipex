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

t_boolean	is_file(t_pipex *pipex, char *file);

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

t_boolean	error_checker(t_pipex *pipex, int argc, char **argv)
{
	char	*err_message;

	err_message = NULL;
	if (argc != 5)
		return (error ("INVALID ARGS NUM"));
	if (!is_file (pipex, argv[INFILE]))
		return (FALSE);
	return (TRUE);
}
