#include "Libft/libft.h"
#include <stdio.h>

void ft_leaks()
{
	system ("leaks a.out");
}

static void ft_pmatrix(char **mat)
{
	int i = 0;

	while (mat[i] != NULL)
	{
		printf("%s\n", mat[i]);
		i++;
	}
}

static void	ft_free(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
	{
		free (matrix[i]);
		i++;
	}
	free (matrix);
}

char	**get_path(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
 		if (!ft_strncmp("PATH=", env[i], 5))
			return (ft_split(env[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

//atexit(ft_leaks);
int main(int argc, char **argv, char **envp)
{
	char **p = get_path(envp);
	char **m = ft_split(argv[1], ' ');

	ft_pmatrix(m);
	printf("\n\n");
	ft_pmatrix(p);
	ft_free(m);
	return (0);
}
