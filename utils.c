#include "pipex.h"

void	ft_free(char **matrix)
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

char	**get_path(char **envp)
{
	int		i = 0;
	char	**path;

	path = NULL;
	while (envp[i] != NULL)
	{
 		if (!ft_strncmp("PATH=", envp[i], 5))
		{
			path = ft_split(envp[i] + 5, ':');
			break ;
		}
		i++;
	}
	i = 0;
	while (path[i] != NULL)
	{
		path[i] = ft_strjoin(path[i], "/");
		i++;
	}
	return (path);
}

char	*get_cmd_path(t_pipex *pipex, char *cmd)
{
	char	*dir;
	int		i;

	i = 0;
	while (pipex->path[i] != NULL)
	{
		dir = ft_strjoin(pipex->path[i], cmd);
		if (access(dir, F_OK) == 0)
			return (dir);
		free (dir);
		i++;
	}
	return (NULL);
}