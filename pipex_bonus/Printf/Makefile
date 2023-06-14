# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/03 12:59:16 by gcastro-          #+#    #+#              #
#    Updated: 2022/06/03 12:59:35 by gcastro-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -glldb
RM		= rm -f
NAME	= printf.a
SRCS	= ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_base.c ft_putvoid.c
OBJS	= ${SRCS:.c=.o}

AR		= ar rc

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
${NAME}:	${OBJS}
	${AR} ${NAME} ${OBJS}
clean:
	${RM} ${OBJS}
fclean: clean
	${RM}  ${NAME}
re: fclean all
.PHONY: all clean fclean re
