/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>					+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:43:18 by gcastro-          #+#    #+#             */
/*   Updated: 2021/11/17 18:43:18 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;

	len_dest = ft_strlen (dest);
	len_src = ft_strlen (src);
	if (!dest || !src)
		return (0);
	if (size < len_dest)
		return (len_src + size);
	else
	{
		dest = dest + len_dest;
		ft_strlcpy (dest, src, size - len_dest);
		return (len_dest + len_src);
	}
}
