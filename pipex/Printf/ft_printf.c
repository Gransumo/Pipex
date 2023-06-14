/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libftprintf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:02:37 by gcastro-          #+#    #+#             */
/*   Updated: 2022/06/03 13:02:39 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_type(va_list args, char c, t_args *ln)
{
	if (c == 'i' || c == 'd')
		ft_putnbr (va_arg(args, int), ln);
	else if (c == 'c')
		ft_putchar (va_arg(args, int), ln);
	else if (c == 's')
		ft_putstr (va_arg(args, char *), ln);
	else if (c == 'u')
		ft_putnbr_unsig (va_arg(args, unsigned int), ln);
	else if (c == 'p')
		ft_putvoid (va_arg(args, unsigned long), ln);
	else if (c == 'x')
		ft_putnbr_base_x (va_arg(args, unsigned int), "0123456789abcdef", ln);
	else if (c == 'X')
		ft_putnbr_base_x (va_arg(args, unsigned int), "0123456789ABCDEF", ln);
	else if (c == '%')
		ft_putchar(c, ln);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	t_args	ln;

	ln.len = 0;
	i = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			print_type(args, str[i + 1], &ln);
			i++;
		}
		else if (str[i] != '%')
			ft_putchar (str[i], &ln);
		i++;
	}
	va_end(args);
	return (ln.len);
}
