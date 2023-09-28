NAME = 			getnextline.a

GET_NEXT_LINE = Src/get_next_line.c \
				Src/get_next_line_utils.c 
    
SRCS = 			${GET_NEXT_LINE}

OBJS = 			${SRCS:.c=.o}

CFLAGS = 		-Wall -Werror -Wextra

%.o:%.c			Makefile Includes/ft_get_next_line.h
				${CC} ${CFLAGS} -I ./ -c $< -o $@
				${CC} ${NAME} ${CFLAGS}

${NAME}:		${OBJS}
				ar rc ${NAME} ${OBJS}

all: 			${NAME}

clean:
				rm -f ${OBJS}

fclean:	clean;
				rm -f ${NAME}

re:	fclean all

.PHONY: 		all clean fclean re
