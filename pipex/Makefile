CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = pipex
HEADER = pipex.h

SRC =	ft_split.c		ft_help_function.c		libft_function.c	pipex.c		pipex_utils.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $^ -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $<

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
