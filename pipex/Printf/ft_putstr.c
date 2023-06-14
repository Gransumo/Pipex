/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:41:20 by gcastro-          #+#    #+#             */
/*   Updated: 2022/04/08 18:41:21 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, t_args *ln)
{
	char	*x;

	if (s == NULL)
	{
		x = "(null)";
		ft_putstr (x, ln);
	}
	else
		ln->len += (int) write (1, s, ft_strlen(s));
}
