
NAME := tester

FILE := main.c \
	mini_parsing.c \
	testing_utils.c \
	token_lst_utils.c \
	escaping_chars.c \
	preserv.c \


HEADERS	:= basic_enums.h \
	mini_parsing.h \
	test_mini.h \
	libft/libft.h

FLAGS := -Wall -Werror -Wextra

OBJS := $(addprefix obj/, $(FILE:.c=.o))

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