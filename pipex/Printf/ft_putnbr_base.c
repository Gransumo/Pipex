/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:19:36 by gcastro-          #+#    #+#             */
/*   Updated: 2021/10/13 12:19:37 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putnbr_base_x(unsigned int nbr, const char *base, t_args *ln)
{
	unsigned int	nbr2;

	nbr2 = nbr;
	if (nbr2 < (unsigned int)ft_strlen (base))
		ft_putchar(base[nbr], ln);
	else if (nbr2 >= (unsigned int)ft_strlen (base))
	{
		ft_putnbr_base_x(nbr2 / ft_strlen(base), base, ln);
		ft_putchar(base[nbr2 % ft_strlen(base)], ln);
	}
}

void	ft_putnbr_base_p(unsigned long nbr, const char *base, t_args *ln)
{
	unsigned long	nbr2;

	nbr2 = nbr;
	if (nbr2 < (unsigned int)ft_strlen (base))
		ft_putchar(base[nbr], ln);
	else if (nbr2 >= (unsigned int)ft_strlen (base))
	{
		ft_putnbr_base_p(nbr2 / ft_strlen(base), base, ln);
		ft_putchar(base[nbr2 % ft_strlen(base)], ln);
	}
}
