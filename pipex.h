#ifndef PIPEX_H
#define PIPEX_H
# include <fcntl.h>
# include "Libft/libft.h"
# include "Printf/ft_printf.h"

typedef enum	e_boolean
{
	TRUE = 1,
	FALSE = 0
}				t_boolean;

typedef struct	s_pipex
{
	char *infile;
	char *file2;
	char **commands;
}				t_pipex;

t_boolean	error_checker();

#endif