/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:34:50 by gcastro-          #+#    #+#             */
/*   Updated: 2023/06/06 18:34:56 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **matrix)
{
	size_t	i;

	i = 0;
	if (matrix != NULL)
	{
		while (matrix[i])
		{
			free (matrix[i]);
			i++;
		}
		free (matrix);
	}
}

static char	**add_final_char(char **m, char *c)
{
	int		i;
	char	*aux;

	i = 0;
	while (m != NULL && m[i] != NULL)
	{
		aux = m[i];
		m[i] = ft_strjoin (m[i], c);
		free (aux);
		i++;
	}
	return (m);
}

char	**get_path(char **envp)
{
	int		i;
	char	**path;

	i = 0;
	path = NULL;
	if (envp == NULL)
		return (NULL);
	while (envp[i] != NULL)
	{
		if (!ft_strncmp ("PATH=", envp[i], 5))
		{
			path = ft_split (envp[i] + 5, ':');
			break ;
		}
		i++;
	}
	path = add_final_char(path, "/");
	return (path);
}

char	*get_cmd_path(t_pipex *pipex, char *cmd)
{
	char	*dir;
	int		i;

	i = 0;
	if (access (cmd, X_OK) == 0)
		return (cmd);
	while (pipex->path != NULL && pipex->path[i] != NULL)
	{
		dir = ft_strjoin (pipex->path[i], cmd);
		if (access (dir, F_OK) == 0)
			return (dir);
		free (dir);
		i++;
	}
	return (NULL);
}

t_boolean	is_file(t_pipex *pipex, char *file)
{
	t_boolean	checker;
	char		*err_message;

	checker = TRUE;
	err_message = ft_strjoin (file, \
	" FILE DOESN'T EXIST OR DOESN'T HAVE PERMISSIONS ENABLED");
	pipex->infile_fd = open (file, O_RDONLY | R_OK);
	if (pipex->infile_fd == -1)
		checker = error (err_message);
	close (pipex->infile_fd);
	free (err_message);
	return (checker);
}
