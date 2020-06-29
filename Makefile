FILE_GENERAL = \
			general_functions \
			median_sort \
			sort_stack \
			stack_functions

FILE_PUSH_SWAP = \
			push_swap \
			$(FILE_GENERAL)


DIR_SRC			= ./src/
DIR_INC			= ./includes/
DIR_LIB			= ./libft/

SRC_PUSH_SWAP 	= $(addprefix $(DIR_SRC), $(addsuffix .c, $(FILE_PUSH_SWAP)))
OBJ_PUSH_SWAP 	= $(addsuffix .o, $(FILE_PUSH_SWAP))

CC 	   			= gcc
PUSH_SWAP 		= push_swap
CFLAGS 	   		= -Wall -Werror -Wextra -O2 -I$(DIR_INC) -I$(DIR_LIB)$(DIR_INC)
#CFLAGS 	   		=  -O2 -I$(DIR_INC) -I$(DIR_LIB)$(DIR_INC)

all: push_swap

lib:
	@make -C $(DIR_LIB)
	@cp libft/libft.a ./

obj_push_swap:
	@$(CC) $(CFLAGS) -c $(SRC_PUSH_SWAP)

push_swap: lib obj_push_swap
	@$(CC) $(CFLAGS) -o $(PUSH_SWAP) $(OBJ_PUSH_SWAP) libft/libft.a

clean:
	@make clean -C $(DIR_LIB)
	@rm -f $(OBJ_PUSH_SWAP)
	@rm -f libft.a

fclean: clean
	@make fclean -C $(DIR_LIB)
	@rm -f $(PUSH_SWAP)

re: fclean all

compile: re
	@clear
	./$(PUSH_SWAP)

.PHONY: all clean fclean re compile

