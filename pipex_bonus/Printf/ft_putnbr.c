/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:41:48 by gcastro-          #+#    #+#             */
/*   Updated: 2022/04/08 18:41:49 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nbr, t_args *ln)
{
	long int	n;

	n = nbr;
	if (n == -2147483648)
	{	
		ft_putchar ('-', ln);
		ft_putchar ('2', ln);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar ('-', ln);
		n = -n;
	}
	if (n <= 9 && n >= 0)
		ft_putchar (n + '0', ln);
	else
	{
		ft_putnbr (n / 10, ln);
		ft_putnbr (n % 10, ln);
	}
}

void	ft_putnbr_unsig(unsigned int n, t_args *ln)
{
	if (n <= 9 && n >= 0)
		ft_putchar (n + '0', ln);
	else
	{
		ft_putnbr (n / 10, ln);
		ft_putnbr (n % 10, ln);
	}
}
