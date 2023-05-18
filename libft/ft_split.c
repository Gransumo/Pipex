/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:40:41 by gcastro-          #+#    #+#             */
/*   Updated: 2022/04/08 18:40:42 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	num_words(char const *str, char caracter)
{
	int		count;
	size_t	alerta;
	size_t	i;

	count = 0;
	alerta = 1;
	i = 0;
	if (str == 0)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == caracter)
			alerta = 1;
		else if (alerta == 1)
		{
			alerta = 0;
			count++;
		}
		i++;
	}
	return (count);
}

static size_t	wrd_len(char const *s, char c, int index)
{
	int		i;
	size_t	len;

	len = 0;
	i = 0;
	if (!s)
		return (0);
	while (index > -1)
	{
		if (s[i] != c)
		{
			index--;
			if (index == -1)
				break ;
			while (s[i] != c)
				i++;
		}
		i++;
	}
	while (s[i + (int)len] != c && s[i + (int)len] != '\0')
		len++;
	return (len);
}

static void	ft_free(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
	{
		free (matrix[i]);
		i++;
	}
	free (matrix);
}

static void	get_value(char const *s, char c, int index, char *dest)
{
	int		i;
	size_t	len;

	if (!dest)
		return ((void)0);
	len = wrd_len (s, c, index) + 1;
	i = 0;
	while (index != 0)
	{
		i++;
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			index--;
		}
	}
	ft_strlcpy (dest, &s[i], len);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	s = ft_strtrim (s, &c);
	matrix = malloc (sizeof (char *) * (num_words(s, c) + 1));
	if (!matrix)
		return (NULL);
	while (i < num_words (s, c))
	{
		matrix[i] = malloc (wrd_len (s, c, i) + 1);
		if (matrix[i] == NULL)
		{
			ft_free (matrix);
			return (0);
		}
		get_value (s, c, i, matrix[i]);
		i++;
	}
	free ((void *)s);
	matrix[i] = NULL;
	return (matrix);
}
