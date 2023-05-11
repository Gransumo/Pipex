/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <gcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:44:49 by gcastro-          #+#    #+#             */
/*   Updated: 2022/04/08 20:04:32 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	const size_t	max = ~((size_t)0);

	if (count != 0 && (max / count) < size)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == 0)
		return (NULL);
	ft_bzero((char *)ptr, count * size);
	return (ptr);
}
