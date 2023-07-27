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

int	error(char *message)
{
	ft_printf ("ERROR\n%s\n", message);
	return (0);
}

void	print_warning(char	*message)
{
	ft_printf ("WARNING\n%s\n", message);
}

void	cmd_error(char *cmd)
{
	char	*err_message;

	err_message = ft_strjoin (cmd, "COMMAND NOT FOUND\n");
	error (err_message);
	free (err_message);
}
