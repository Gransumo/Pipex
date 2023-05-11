/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:34:22 by gcastro-          #+#    #+#             */
/*   Updated: 2022/09/25 14:34:51 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_line(char	*save, int fd)
{
	char	*buff;
	int		n_bytes;

	n_bytes = 1;
	buff = malloc (BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	while (!ft_strchr(save, '\n') && n_bytes != 0)
	{
		n_bytes = read (fd, buff, BUFFER_SIZE);
		if (n_bytes == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[n_bytes] = 0;
		if (!save)
		{
			save = malloc (1);
			save[0] = 0;
		}
		save = ft_strjoin_gnl (save, buff);
	}
	free (buff);
	return (save);
}

char	*ft_set_new(char *save)
{
	char	*new;
	size_t	i;
	size_t	len;

	if (!save[0])
		return (NULL);
	i = 0;
	len = len_new (save);
	new = malloc (len + 1);
	if (new == NULL)
		return (NULL);
	while (i < len)
	{
		new[i] = save[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_set_saved(char *save)
{
	char	*n_save;
	size_t	i;
	size_t	len;

	if (!save)
		return (NULL);
	i = 0;
	len = len_new(save);
	n_save = malloc(ft_strlen(&save[len]) + 1);
	if (!n_save)
		return (NULL);
	while (save[len + i] != '\0')
	{
		n_save[i] = save[len + i];
		i++;
	}
	n_save[i] = 0;
	if (ft_strlen(&save[len]) == 0)
	{
		free (n_save);
		n_save = NULL;
	}
	free (save);
	return (n_save);
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		*new;

	if (fd < 0)
		return (NULL);
	save = get_line (save, fd);
	if (!save)
		return (NULL);
	new = ft_set_new (save);
	save = ft_set_saved (save);
	return (new);
}
