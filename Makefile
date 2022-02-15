NAME1 = ./server
NAME2 = ./client
BONUS1 = ./server_bonus
BONUS2 = ./client_bonus

SRC1 = ./server.c ./utility.c
SRC2 = ./client.c ./utility.c

SRCB1 = ./server_bonus.c ./utility.c
SRCB2 = ./client_bonus.c ./utility.c

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

OBJB1 = $(SRCB1:.c=.o)
OBJB2 = $(SRCB2:.c=.o)

HDRS = ./lib.h

RM = rm -f

CC = gcc -Wall -Wextra -Werror

.c.o = ${CC} -I ${HDRS} -c $< -o ${<:.c=.o}

all: $(NAME1) $(NAME2)

$(NAME1): ${OBJ1}

$(NAME2): $(OBJ2)

$(BONUS1): $(OBJB1)

$(BONUS2): $(OBJB2)

bonus: all $(BONUS1) $(BONUS2) clean

clean:
	${RM} $(OBJ1)
	$(RM) $(OBJ2)
	$(RM) $(OBJB1)
	$(RM) $(OBJB2)

fclean: clean
	${RM} $(NAME1)
	$(RM) $(NAME2)
	$(RM) $(BONUS1)
	$(RM) $(BONUS2)

re: fclean all

.PHONY: all bonus clean fclean re
