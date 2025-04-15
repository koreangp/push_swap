NAME = push_swap
NAME_BONUS = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
LIBFTDIR = ./libft
HEADER = ./pushswap/push_swap.h

SRC = ./pushswap/push_swap.c ./pushswap/stack_init.c ./pushswap/rotate.c ./pushswap/push.c ./pushswap/rev_rotate.c \
	  ./pushswap/utils.c ./pushswap/swap.c ./pushswap/sort.c ./pushswap/stack_free.c \
	  ./pushswap/set_new_algo.c ./pushswap/stack_init_utils.c ./pushswap/algo_utils.c ./pushswap/moves_algo.c \
	  ./pushswap/algo_regime.c ./pushswap/algo_utils_deux.c
	  
BONUS_SRC =	./check/checker.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c ./check/goodbad.c  \
			./pushswap/stack_init.c ./pushswap/rotate.c ./pushswap/push.c ./pushswap/rev_rotate.c \
	  		./pushswap/utils.c ./pushswap/swap.c ./pushswap/set_new_algo.c ./pushswap/sort.c \
			./pushswap/stack_free.c ./pushswap/stack_init_utils.c ./pushswap/algo_utils.c \
			./pushswap/algo_regime.c ./pushswap/moves_algo.c ./pushswap/algo_utils_deux.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)
OBJ = $(SRC:.c=.o)

GREEN    = \033[38;5;76m
RED        = \033[38;5;160m
YELLOW    = \033[38;5;226m
ORANGE    = \033[38;5;202m
PURPLE    = \033[38;5;213m
LBLUE    = \033[38;5;51m
BLUE    = \033[38;5;117m
INDI    = \033[38;5;99m
RESET    = \033[00m

all: $(NAME)
	@printf "$(YELLOW)\n"
	@echo "⠀⠀⠀⠰⣌⣘⠃⢂⠁⠀⠐⠁⠠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⢌⠘⣿⣦⣠"
	@echo "⠀⠀⠀⢠⡾⣷⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⢿⣿⣏"
	@echo "⠀⠀⠀⢈⣷⡔⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⣆"
	@echo "⠀⠒⠾⢿⡭⠀⠀⠀⠀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢘⣿"
	@echo "⠀⠀⡐⢡⣣⠀⠀⠀⠀⣇⢻⢆⠃⠀⠀⠀⠀⡤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡏"
	@echo "⠀⠀⠀⠸⢻⠀⠀⠀⠄⠀⠘⢄⠐⠅⣀⣥⣠⣼⣿⣿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⢜⣀"
	@echo "⠀⠀⠀⣀⢆⠀⠀⠀⣄⢀⡠⡐⣶⣿⣿⣿⣿⣿⣿⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⢀⢫⡁"
	@echo "⠀⠀⠀⠀⠈⠀⠀⠘⢸⣿⣇⠈⠉⠉⣹⣿⣿⣿⡿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠸⡄⠑"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣷⠠⠾⢟⣛⡋⠉⢰⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠡⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⣿⣆⠉⠁⣀⣀⠀⣾⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⢗"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣇⠬⠭⢑⡴⣿⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⣏⠩⢉⣴⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠻⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"

$(NAME): $(OBJ)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) -I$(HEADER) -o $@ $(OBJ) -L ${LIBFTDIR} -lft 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	cd $(LIBFTDIR) && make clean

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all

$(NAME_BONUS) :$(BONUS_OBJ)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) -I$(HEADER) -o $@ $(BONUS_OBJ) -L ${LIBFTDIR} -lft 

bonus : $(NAME_BONUS)
	@printf "$(PURPLE)\n"
	@echo "⠀⠀⠀⠀⠀⠀⠀⢀⢤⣠⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⣀⣗⢿⣻⣻⢧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⣀⡾⣃⣵⠎⢼⣻⣷⣆⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⢀⣤⢘⣾⢋⠙⠫⠉⠻⡟⣻⣻⣆⠀⠀⠀⠀⠀⠀⠀⠛⣒⣰⣦⡀⠀⠀⠀⠀⠀"
	@echo "⠀⢘⣟⣟⡟⠁⠁⠠⣢⣶⣶⣄⢭⢽⣻⣦⣄⠀⠀⠀⠀⠀⢕⣧⣻⣶⢻⡆⠀⠀⠀⠀"
	@echo "⠀⣼⣾⡯⠈⣶⣀⣯⣮⣟⣟⣻⠷⠀⠻⠎⠟⡄⠀⠀⠀⠀⠐⣈⣷⣶⡿⠁⠀⠀⠀⠀"
	@echo "⠀⠋⣛⠓⠒⠋⣽⣸⢫⣥⣲⣻⣻⣾⣧⡀⠈⡷⠀⠀⠀⠀⢘⣽⠟⣻⣇⢣⢀⠀⠀⠀"
	@echo "⠀⠸⣻⢦⠀⠈⠒⠈⣼⠟⣻⣻⢻⣻⣻⣻⡄⠀⠀⠀⠀⠀⠘⠾⠀⢻⣃⢀⠙⠓⠏⠀"
	@echo "⠀⠈⠚⠋⠀⠀⠀⠀⣈⣍⣻⡟⣻⢹⣻⣻⣻⢗⡀⠀⠀⠀⠀⠀⠱⣯⣻⣷⠦⠖⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⡠⣪⣾⣷⡟⡼⡇⠀⠀⠉⢧⣮⣻⣇⠀⠀⠀⠀⠀⠙⢿⢶⡀⠘⠀⠀"
	@echo "⠀⠀⠀⠀⢀⣴⣻⣻⡿⣻⣯⡖⠀⠀⠀⠀⠙⢿⣻⣻⣶⣀⠀⠀⠀⠀⠀⠈⠗⠀⠀⠀"
	@echo "⠀⠀⠀⢠⣻⣻⣻⣻⣻⣴⡿⠃⠀⠀⠀⠀⠀⠀⠀⠉⠙⠿⡠⠄⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⢹⣹⣻⣟⢿⢿⣻⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⢀⢺⣻⣻⡿⢏⣽⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"


.PHONY: all clean fclean re bonus