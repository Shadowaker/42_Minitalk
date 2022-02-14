NAME1 = ./server
NAME2 = ./client

SRC1 = ./server.c \
./utility.c

SRC2 = ./client.c \
./utility.c

OBJ1 = $(SRC1:.c=.o)

OBJ2 = $(SRC2:.c=.o)

HDRS = ./lib.h

RM = rm -f

CC = gcc -Wall -Wextra -Werror

.c.o = ${CC} -I ${HDRS} -c $< -o ${<:.c=.o}

all: $(NAME1) $(NAME2) clean

$(NAME1): ${OBJ1}

$(NAME2): $(OBJ2)

clean:
	${RM} $(OBJ1)
	$(RM) $(OBJ2)

fclean: clean
	${RM} $(NAME1)
	$(RM) $(NAME2)

re: fclean all

.PHONY: all clean fclean re
