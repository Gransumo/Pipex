/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executables.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:34:23 by gcastro-          #+#    #+#             */
/*   Updated: 2023/06/06 18:34:24 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	finish(int *fd)
{
	close(fd[READ_FD]);
	exit(0);
}

void	ex_cmd(t_pipex *pipex, char *cmd)
{
	char	**exe;
	char	*cmd_path;

	exe = ft_split (cmd, ' ');
	cmd_path = get_cmd_path (pipex, exe[0]);
	if (cmd_path == NULL)
		exit (0);
	execve (cmd_path, exe, pipex->envp);
	free (cmd_path);
	ft_free (exe);
}

void	ex_first_cmd(int *fd, t_pipex *pipex)
{
	close(fd[READ_FD]);
	dup2(pipex->infile_fd, STDIN_FILENO);
	dup2(fd[WRITE_FD], STDOUT_FILENO);
	close(fd[WRITE_FD]);
	ex_cmd(pipex, pipex->argv[2]);
}

void	ex_last_cmd(int *fd, t_pipex *pipex)
{
	dup2(fd[READ_FD], STDIN_FILENO);
	close(fd[READ_FD]);
	dup2(pipex->outfile_fd, STDOUT_FILENO);
	close(pipex->outfile_fd);
	ex_cmd(pipex, pipex->argv[3]);	
}
