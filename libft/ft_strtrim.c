/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:39:44 by gcastro-          #+#    #+#             */
/*   Updated: 2022/04/08 18:39:45 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	cut_right(size_t len, char const *s1, char const *set)
{
	int	i;
	int	j;

	i = (int)ft_strlen (s1);
	j = 0;
	if (len == 0)
		return (len);
	while (i > 0)
	{
		while (set[j] != '\0')
		{
			if (s1[i - 1] == set[j])
			{
				len--;
				break ;
			}
			j++;
		}
		if (j == (int)ft_strlen (set))
			break ;
		j = 0;
		i--;
	}
	return (len);
}

size_t	new_len(char const *s1, char const *set)
{
	int		i[2];
	size_t	len;

	i[0] = 0;
	i[1] = 0;
	len = ft_strlen (s1);
	while (s1[i[0]] != '\0')
	{
		while (set[i[1]] != '\0')
		{
			if (s1[i[0]] == set[i[1]])
			{
				len--;
				break ;
			}
			i[1]++;
		}
		if (i[1] == (int)ft_strlen (set))
			break ;
		i[1] = 0;
		i[0]++;
	}
	len = cut_right (len, s1, set);
	return (len);
}

static char	*get_value(char const *s1, char const *set, char *str)
{
	int		i[2];
	size_t	len;

	len = 0;
	i[0] = 0;
	i[1] = 0;
	while (s1[i[0]] != '\0')
	{
		while (set[i[1]] != '\0')
		{
			if (s1[i[0]] == set[i[1]])
			{
				len--;
				break ;
			}
			i[1]++;
		}
		if (i[1] == (int)ft_strlen (set))
			break ;
		i[1] = 0;
		i[0]++;
	}
	ft_strlcpy (str, &s1[i[0]], new_len (s1, set) + 1);
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup (s1));
	if (new_len (s1, set) == 0)
		return (ft_strdup ("\0"));
	str = malloc (sizeof(char) * (new_len (s1, set) + 1));
	if (str == 0)
		return (0);
	str = get_value (s1, set, str);
	return (str);
}