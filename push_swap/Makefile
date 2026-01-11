OBJ_F = mandatory/push_swap.o mandatory/linked_list_function.o mandatory/free_function.o\
		mandatory/move/move_push.o mandatory/move/move_swap.o mandatory/move/move_rotate.o\
		mandatory/algo_utile.o mandatory/ft_split.o mandatory/emergency.o mandatory/algo.o\
		mandatory/ft_split_utile.o mandatory/algo_important_part.o mandatory/move/move_reverse_rotate.o\
		

BONUS_O_F = bonus/push_swap_utile_bonus.o bonus/push_swap_bonus.o mandatory/algo_utile.o\
			mandatory/move/move_push.o mandatory/move/move_swap.o mandatory/move/move_rotate.o\
			mandatory/ft_split.o mandatory/ft_split_utile.o mandatory/move/move_reverse_rotate.o\
			bonus/get_next_line/get_next_line_utils_bonus.o bonus/get_next_line/get_next_line_bonus.o\
			mandatory/free_function.o mandatory/linked_list_function.o bonus/push_swap_check_bonus.o\
			

NAME = push_swap
BONUS_NAME = checker
CFLAGS = -Wall -Wextra -Werror

HEADER = push_swap.h

all : $(NAME)
	@echo "\033[1;32mCompilation Completed Successfully! ✅\033[0;m"

bonus : $(BONUS_NAME)
	@echo "\033[1;32mBonus Compilation Completed Successfully! ✅\033[0;m"

$(NAME) : $(OBJ_F) 
	@cc $(CFLAGS) $(OBJ_F) -o $(NAME) 

$(BONUS_NAME) : $(BONUS_O_F) 
	@cc $(CFLAGS) $(BONUS_O_F) -o $(BONUS_NAME) 

mandatory/%.o :  mandatory/%.c $(HEADER)
	@echo "\033[0;34mCompiling $< .\033[0;m"
	@sleep 0.2
	@cc $(CFLAGS) -c $< -o $@

mandatory/move/%.o :  mandatory/move/%.c $(HEADER)
	@echo "\033[0;34mCompiling $< .\033[0;m"
	@sleep 0.2
	@cc $(CFLAGS) -c $< -o $@

bonus/get_next_line/%.o :  bonus/get_next_line/%.c $(HEADER)
	@echo "\033[0;34mCompiling $< .\033[0;m"
	@sleep 0.2
	@cc $(CFLAGS) -c $< -o $@

bonus/%.o :  bonus/%.c $(HEADER)
	@echo "\033[0;34mCompiling $< .\033[0;m"
	@sleep 0.2
	@cc $(CFLAGS) -c $< -o $@

clean :
	@echo "\033[0;31mRemoving object files.\033[0;m"
	@sleep 0.2
	@rm -f $(OBJ_F) $(BONUS_O_F)
	@echo "\033[1;32mCleaning DONE ✅\033[0;m"
	
fclean : clean
	@echo "\033[0;31mRemoving program.\033[0;m"
	@sleep 0.2
	@rm -rf $(NAME) $(BONUS_NAME)
	@echo "\033[1;32mDONE ✅\033[0;m"

re : fclean all
