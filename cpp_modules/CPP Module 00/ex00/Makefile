
CC = c++

CC += -Wall -Wextra -Werror -std=c++98

NAME = megaphone

OBJ_F = megaphone.o

all : $(NAME)

$(NAME) : $(OBJ_F)
	@$(CC) $(OBJ_F) -o $(NAME)
	@echo "✅ \033[1;32mCompilation Completed Successfully!\033[0;m"

%.o : %.cpp
	@$(CC) -c $< -o $@
	@echo "\033[1;30mObject files generated Successfully! $@ \033[0;m"

clean :
	@rm -f $(OBJ_F)
	@echo "\033[31mObject files has been removed Successfully! ✅\033[0;m"

fclean : clean
	@rm -f $(NAME)
	@echo "\033[31mExecutable file has been removed Successfully! ✅\033[0;m"

re : fclean all