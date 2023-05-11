
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -glldb
RM		= rm -f
NAME	= libft.a
SRCS	=  ft_calloc.c ft_strlen.c ft_bzero.c
OBJS	= ${SRCS:.c=.o}
AR		= ar rc

all:	${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	${AR} ${NAME} ${OBJS}
clean:
	${RM} ${OBJS}
fclean:	clean
	${RM} ${NAME}
re: fclean all
.PHONY:	all clean fclean re
