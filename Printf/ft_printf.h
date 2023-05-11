/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:02:12 by gcastro-          #+#    #+#             */
/*   Updated: 2022/06/03 13:02:15 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../gnl/get_next_line.h"
# include "../Printf/ft_printf.h"

typedef struct s_args
{
	int	len;
}	t_args;
int		ft_strlen(const char *c);
int		ft_printf(char const *str, ...);
void	ft_putchar(char c, t_args *ln);
void	ft_putstr(char *s, t_args *ln);
void	ft_putnbr(int nbr, t_args *ln);
void	ft_putnbr_unsig(unsigned int n, t_args *ln);
void	ft_putnbr_base_x(unsigned int nbr, const char *base, t_args *ln);
void	ft_putnbr_base_p(unsigned long nbr, const char *base, t_args *ln);
void	ft_putvoid(unsigned long s, t_args *ln);
#endif
