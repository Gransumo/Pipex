/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>					+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:55:47 by gcastro-          #+#    #+#             */
/*   Updated: 2022/09/14 21:19:42 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include "../gnl/get_next_line.h"
# include "../Printf/ft_printf.h"

void	*ft_calloc(size_t count, size_t size);
int	ft_strlen(const char *c);
void	ft_bzero(void *s, size_t n);

#endif
