NAME1 = ./server
NAME2 = ./client

SRC = ./server.c \
./client.c
./utility.c

OBJS = $(SRC:.c=.o)

HDRS = ./lib.h

RM = rm -f

CC = gcc -Wall -Wextra -Werror

.c.o = ${CC} -I ${HDRS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

all: $(NAME)

clean:
	${RM} $(OBJS)

fclean: clean
	${RM} $(NAME)

re: fclean all

.PHONY: all clean fclean re
