#ifndef PIPEX_H
#define PIPEX_H
#define READ_FD 0
#define	WRITE_FD 1
# include <fcntl.h>
# include "Libft/libft.h"
# include "Printf/ft_printf.h"
# include "gnl/get_next_line.h"

typedef enum	e_boolean
{
	TRUE = 1,
	FALSE = 0
}				t_boolean;

typedef struct	s_pipex
{
	char	**path;
	char	**envp;
	char	*infile;
	char	*outfile;
	int		pid;
	int		cmd_fd[2];
	int		infile_fd;
	int		outfile_fd;
	int		iter;
}				t_pipex;

void  ft_pipex(t_pipex *pipex, int argc, char **argv);
t_boolean	ex_cmd(t_pipex *pipex, char *cmd);
void init_exc(t_pipex *pipex, char **argv);
void last_exc(t_pipex *pipex, char *argv);

int		error(char *message);
void	*null_error(char **message);
t_boolean error_checker(int argc, char **argv);
void	ft_free(char **matrix);
char	**get_path(char **envp);
char	*get_cmd_path(t_pipex *pipex, char *cmd);

#endif