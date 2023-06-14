/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:34:33 by gcastro-          #+#    #+#             */
/*   Updated: 2023/06/06 18:34:40 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"

void ft_leaks()
{
	system("leaks pipex");
}
/*  void ft_pmatrix(char **mat)
{
	int i = 0;

	while (mat[i] != NULL)
	{
		printf("%s\n", mat[i]);
		i++;
	}
} */
void	finish(int *fd);

void	init_pvars(t_pipex *pipex, int argc,  char **argv, char **envp)
{
	if (error_checker (pipex, argc, argv) == FALSE)
		exit(0);
	pipex->outfile_fd = open (argv[OUTFILE], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex->outfile_fd == -1)
		exit(0);
	pipex->argv = argv;
	pipex->path = get_path (envp);
	pipex->envp = envp;
}


int	main(int argc, char **argv, char **envp)
{
	t_pipex		pipex;
	pid_t		pid;
	int			fd[2];

	atexit(ft_leaks);
	init_pvars(&pipex, argc, argv, envp);
	if(pipe(fd) == -1)
		return (error("PIPE ERROR"));
	pid = fork();
	if (pid == -1)
		return (error("FORK ERROR"));
	if (pid == 0)
		ex_first_cmd(fd, &pipex);
	else
	{
		close(fd[WRITE_FD]);
		pid = fork();
		if (pid == -1)
			return (error("SECOND FORK ERROR"));
		if (pid == 0)
			ex_last_cmd(fd, &pipex);
		else
			finish(fd);
	}
	return (0);
}
