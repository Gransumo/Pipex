/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:40:15 by gcastro-          #+#    #+#             */
/*   Updated: 2022/04/08 18:40:16 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (s1 == NULL || s2 == NULL)
		return (0);
	new = malloc (ft_strlen (s1) + ft_strlen (s2) + 1);
	if (new == NULL)
		return (0);
	ft_strlcpy (new, s1, ft_strlen (s1) + 1);
	ft_strlcat (new, s2, ft_strlen (s1) + ft_strlen (s2) + 1);
	return (new);
}
