CC			= gcc
CFLAGS		= -Wall -Werror -Wextra #-fsanitize=address -g #-glldb
RM			= rm -f
NAME		= pipex
SRCS		= pipex.c error.c executables.c utils.c
OBJS		= ${SRCS:.c=.o}
AR			= ar rc


LIBFT_DIR	= libft/
LIBFT_A		= libft.a
LIBFT		= $(addprefix $(LIBFT_DIR), $(LIBFT_A))

PRINTF_DIR	= Printf/
PRINTF_A	= printf.a
PRINTF		= $(addprefix $(PRINTF_DIR), $(PRINTF_A))

GNL			= get_next_line.c get_next_line_utils.c
SRC_GNL		= $(addprefix gnl/, $(GNL))
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all:	${NAME}

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)


#$(OBJS): $(SRCS)
#	$(CC) $(FLAGS) -c $(SRCS)
clean:
	${RM} ${OBJS}
fclean:	clean
	${RM} ${NAME}
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
re: fclean all
.PHONY:	all clean fclean re

