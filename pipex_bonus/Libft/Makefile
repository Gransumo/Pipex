
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -glldb
RM		= rm -f
NAME	= libft.a
SRCS	= ft_bzero.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
			 ft_calloc.c ft_strjoin.c ft_split.c ft_strtrim.c ft_strdup.c
OBJS	= ${SRCS:.c=.o}
SRCS_B = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c\
			ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c 			\
			ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS_B = ${SRCS_B:.c=.o}

AR		= ar rc

all:	${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	${AR} ${NAME} ${OBJS}

#BONUS_PART

bonus:
	make $(NAME) SRCS='$(SRCS) $(SRCS_B)'
clean:
	${RM} ${OBJS} ${OBJS_B}
fclean:	clean
	${RM} ${NAME}
re: fclean all
.PHONY:	all clean fclean re bonus
