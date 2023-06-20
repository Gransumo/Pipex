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

void	ft_pipex(t_pipex *pipex, char *cmd)
{
	pid_t	pid;
	int		fd[2];

	pipe (fd);
	pid = fork ();
	if (pid == 0)
	{
		close (fd[READ_FD]);
		dup2 (pipex->fd[READ_FD], STDIN_FILENO);
		dup2 (fd[WRITE_FD], STDOUT_FILENO);
		close (pipex->fd[READ_FD]);
		close (fd[WRITE_FD]);
		ex_cmd (pipex, cmd);
	}
	else
	{
		close (pipex->fd[READ_FD]);
		close (fd[WRITE_FD]);
		dup2 (fd[READ_FD], pipex->fd[READ_FD]);
		waitpid (pid, NULL, 0);
	}
}

void	init_exc(t_pipex *pipex, char **argv)
{
	pid_t	pid;

	pipe (pipex->fd);
	pid = fork ();
	if (pid == 0)
	{
		close (pipex->fd[READ_FD]);
		dup2 (pipex->infile_fd, STDIN_FILENO);
		dup2 (pipex->fd[WRITE_FD], STDOUT_FILENO);
		close (pipex->fd[WRITE_FD]);
		close (pipex->infile_fd);
		ex_cmd (pipex, argv[2]);
	}
	else
		close (pipex->fd[WRITE_FD]);
}

void	last_exc(t_pipex *pipex, char *argv)
{
	pid_t	pid;

	pid = fork ();
	if (pid == 0)
	{
		dup2 (pipex->fd[READ_FD], STDIN_FILENO);
		dup2 (pipex->outfile_fd, STDOUT_FILENO);
		close (pipex->outfile_fd);
		close (pipex->fd[READ_FD]);
		ex_cmd (pipex, argv);
	}
	else
	{
		close (pipex->fd[READ_FD]);
	}
}
