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

/* void ft_leaks()
{
	system("leaks pipex");
} */
/*  void ft_pmatrix(char **mat)
{
	int i = 0;

	while (mat[i] != NULL)
	{
		printf("%s\n", mat[i]);
		i++;
	}
} */
t_pipex	init_pvars(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	pipex.infile = argv[1];
	pipex.outfile = argv[argc - 1];
	pipex.infile_fd = open (pipex.infile, O_RDONLY);
	pipex.outfile_fd = open (pipex.outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex.infile_fd < 0 || pipex.outfile_fd < 0)
		print_warning("A FILE DOESN'T EXIST OR DOESN'T HAVE PERMISSIONS \
		ENABLED");
	pipex.path = get_path (envp);
	pipex.envp = envp;
	pipex.iter = 3;
	return (pipex);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex		pipex;
	int	i;

	i = 0;
	if (argc < 5)
		return (error("WRONG ARGS NUMBER\n"));
	pipex = init_pvars (argc, argv, envp);
	init_exc (&pipex, argv);
	while (pipex.iter < argc - 2)
		ft_pipex (&pipex, argv[pipex.iter++]);
	i = last_exc (&pipex, argv[argc - 2]);
	ft_free (pipex.path);
	return (i);
}
