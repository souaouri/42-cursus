CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Unnecessary_violence
HEADER = Weapon.hpp HumanA.hpp HumanB.hpp
OBJ_F = Weapon.o main.o HumanA.o HumanB.o

all: $(NAME)

$(NAME): $(OBJ_F)
	@$(CC) $(OBJ_F) -o $(NAME)
	@echo "✅ \033[1;32mCompilation Completed Successfully!\033[0;m"

%.o: %.cpp $(HEADER)
	@$(CC) $(CFLAGS) -c $<
	@echo "\033[1;30mObject files generated Successfully! $@ \033[0;m"

clean:
	@rm -f $(OBJ_F)
	@echo "\033[31mObject files have been removed Successfully! ✅\033[0;m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31mExecutable file has been removed Successfully! ✅\033[0;m"

re: fclean all