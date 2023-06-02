#include "pipex.h"

t_boolean	ex_cmd(t_pipex *pipex, char *cmd)
{
	char **exe;
	char *cmd_path;
	char *err_message;

	if (pipex->pid == 0)
	{
		err_message = ft_strjoin("No existe el comando ", cmd);
		exe = ft_split(cmd, ' ');
		cmd_path = get_cmd_path(pipex, exe[0]);
		if (cmd_path == NULL)
		{
			error(err_message);
			free (err_message);
			return (FALSE);
		}
		execve(cmd_path, exe, pipex->envp);
		free (cmd_path);
		free (err_message);
		ft_free(exe);
	}
	return (TRUE);
}

void  ft_pipex(t_pipex *pipex, int argc, char **argv)
{
	if (pipex->iter < argc - 2)
	{
		pipex->pid = fork();
		if (pipex->pid == 0)
		{
			dup2(pipex->cmd_fd[READ_FD], STDIN_FILENO);
			dup2(pipex->cmd_fd[WRITE_FD], STDOUT_FILENO);
			close(pipex->cmd_fd[READ_FD]);
			close(pipex->cmd_fd[WRITE_FD]);
			ex_cmd(pipex, argv[pipex->iter]);
		}
		else
		{
			close(pipex->cmd_fd[WRITE_FD]);
			pipex->iter++;
			ft_pipex(pipex, argc, argv);
			close(pipex->cmd_fd[READ_FD]);
		}
	}
}

void init_exc(t_pipex *pipex, char **argv)
{
	if (pipex->pid == 0)
	{
		close(pipex->cmd_fd[READ_FD]);
		pipex->infile_fd = open(pipex->infile, O_RDONLY);
		dup2(pipex->infile_fd, STDIN_FILENO);
		dup2(pipex->cmd_fd[WRITE_FD], STDOUT_FILENO);
		close(pipex->cmd_fd[WRITE_FD]);
		close(pipex->infile_fd);
		ex_cmd(pipex, argv[2]);
	}
}

void last_exc(t_pipex *pipex, char *argv)
{
	close(pipex->cmd_fd[WRITE_FD]);
	pipex->pid = fork();
	if (pipex->pid == 0)
	{
		dup2(pipex->cmd_fd[READ_FD], STDIN_FILENO);
		dup2(pipex->outfile_fd, STDOUT_FILENO);
		close(pipex->cmd_fd[READ_FD]);
		close(pipex->outfile_fd);
		ex_cmd(pipex, argv);
	}
}
