/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:25:23 by gcastro-          #+#    #+#             */
/*   Updated: 2022/09/25 14:34:34 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strjoin_gnl(char *save, char *buff)
{
	char	*ptr;
	int		i;
	int		j;

	if (save == NULL && buff == NULL)
		return (NULL);
	ptr = malloc (ft_strlen(save) + ft_strlen(buff) + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (save)
	{
		while (save[i] != 0)
		{
			ptr[i] = save[i];
			i++;
		}
	}
	while (buff[j] != 0)
		ptr[i++] = buff[j++];
	ptr[ft_strlen(save) + ft_strlen(buff)] = '\0';
	free (save);
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	x;
	size_t	i;

	i = 0;
	x = ft_strlen ((char *)s);
	while (i < x)
	{
		if (*s == (unsigned char)c)
			return ((char *) s);
		s++;
		i++;
	}
	return (NULL);
}

size_t	len_new(char *save)
{
	size_t	len;

	len = 0;
	if (!save)
		return (0);
	while (save[len] != '\0')
	{
		if (save[len] == '\n')
		{
			len ++;
			break ;
		}
		len++;
	}
	return (len);
}
