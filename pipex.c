
#include <stdio.h>
#include "pipex.h"

void ft_pmatrix(char **mat)
{
	int i = 0;

	while (mat[i] != NULL)
	{
		printf("%s\n", *mat);
		i++;
	}
}

t_pipex init_pvars(int argc, char **argv)
{
	t_pipex	pipex;
	int		i;
	int		j;

	pipex.infile = argv[0];
	pipex.file2 = argv[argc];
	pipex.commands = malloc(sizeof (char *) * (argc - 2));
	i = 2;
	j = 0;
	while (argv[i] != NULL)
	{
		if (!(ft_strlen(argv[i]) == 1 && argv[i][0] == '|'))
		{
			pipex.commands[j] = argv[i];
			j++;
		}
		i++;
	}
	return (pipex);
}

int main(int argc, char **argv)
{
	t_pipex pipex;

	if (!error_checker(argc, argv))
		return (0);
	pipex = init_pvars(argc, argv);
	ft_pmatrix(pipex.commands);
	return (0);
}
