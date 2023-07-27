/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:34:43 by gcastro-          #+#    #+#             */
/*   Updated: 2023/06/06 18:34:44 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define READ_FD 0
# define WRITE_FD 1
# include <fcntl.h>
# include "Libft/libft.h"
# include "Printf/ft_printf.h"
# include "gnl/get_next_line.h"

typedef enum e_boolean
{
	TRUE = 1,
	FALSE = 0
}			t_boolean;

typedef struct s_pipex
{
	char	**path;
	char	**envp;
	char	*infile;
	char	*outfile;
	int		term_fd;
	int		fd[2];
	int		infile_fd;
	int		outfile_fd;
	int		iter;
}			t_pipex;

void		ft_pipex(t_pipex *pipex, char *cmd);
void		ex_cmd(t_pipex *pipex, char *cmd);
void		init_exc(t_pipex *pipex, char **argv);
int			last_exc(t_pipex *pipex, char *argv);
int			error(char *message);
void		print_warning(char	*message);
void		ft_free(char **matrix);
char		**get_path(char **envp);
char		*get_cmd_path(t_pipex *pipex, char *cmd);

#endif
