
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

t_pipex init_pvars(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	pipex.infile = argv[1];
	pipex.outfile = argv[argc - 1];
	pipex.outfile_fd = open(pipex.outfile, O_WRONLY | O_CREAT, 0777);
	pipex.path = get_path(envp);
	pipex.envp = envp;
	pipex.iter = 3;
	return (pipex);
}

int main(int argc, char **argv, char **envp)
{
	t_pipex		pipex;
	//int			status;

	atexit(ft_leaks);
	if (error_checker(argc, argv) == FALSE)
		return (0);
	pipex = init_pvars(argc, argv, envp);
	pipe(pipex.cmd_fd);
	pipex.pid = fork();
	if (pipex.pid == 0)
		init_exc(&pipex, argv);
	else
	{
		ft_pipex(&pipex, argc, argv);
		last_exc(&pipex, argv[argc - 2]);
		while (argc-- <= 3)
			ft_free(pipex.path);
	}
	return (0);
}
