
NAME := ./tester

FILE := main.c \
	mini_parsing.c \
	testing_utils.c \
	token_lst_utils.c \
	escaping_chars.c \
	preserv.c \
	simple_quoting.c \
	double_quoting.c \
	split_toklst_on_meta.c \
	split_on_meta.c \
	expand_variable.c \
	suppress_quotes.c \
	instruction_block_tree_utils.c \
	instruction_block_chain.c \
	instruction_block_tree_debug.c \
	str_token_debug.c \
	token_to_str_token.c \
	t_string_token_utils.c \
	init_pipe_arr_on.c \


HEADERS	:= basic_enums.h \
	mini_parsing.h \
	test_mini.h \
	libft/libft.h

FLAGS := -Wall -Werror -Wextra -g3 #-D SILENCIEUX=false

OBJS := $(addprefix obj/, $(FILE:.c=.o))

test	: $(NAME)
	valgrind --leak-check=full $(NAME) 

all : $(NAME)

$(NAME) : $(OBJS) $(HEADERS)
	make -C libft
	gcc -o $(NAME) $(OBJS) $(addprefix  -I./, $(HEADERS)) -L./libft -lft


./obj/%.o : %.c
	gcc $(FLAGS) -o $@ -c $< -I libft

re	: fclean
	make

fclean	: clean
	rm $(NAME)

clean :
	rm -rf obj
	mkdir obj
	make -C libft fclean
