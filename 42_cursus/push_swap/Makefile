# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/28 17:29:30 by bdruez            #+#    #+#              #
#    Updated: 2021/09/13 22:43:36 by bdruez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
# ====> PATHS                                                                  #
# ---------------------------------------------------------------------------- #

PATH_SRCS		= ./srcs/
PATH_INCS		= ./includes/ ./libft/includes/ ./tests/includes/
PATH_OBJS		= ./objs/
PATH_LFT		= ./libft/

PATH_TEST		= ./tests/
TEST_PREFIX		= test_

# ---------------------------------------------------------------------------- #
# ====> FILES                                                                  #
# ---------------------------------------------------------------------------- #

F_SRCS		= chunk.c \
			  doublons.c \
			  exit_management.c \
			  parser.c \
			  print.c \
			  sort.c \
			  sort_less_than_five.c \
			  sort_less_than_hundred.c \
			  sort_more_than_hundred.c \
			  t_stack.c \
			  t_stack_action.c \
			  t_stack_ele.c \
			  t_stack_utils.c \

F_TEST		= $(addprefix $(TEST_PREFIX), $(F_SRCS))

# ---------------------------------------------------------------------------- #
# ====> VARIABLES                                                              #
# ---------------------------------------------------------------------------- #

OBJS		= $(addprefix $(PATH_OBJS), $(F_SRCS:.c=.o))
OBJS_TEST	= $(addprefix $(PATH_OBJS), $(F_TEST:.c=.o))

MAIN_BIN	= $(PATH_OBJS)main.o
T_MAIN_BIN	= $(PATH_OBJS)t_main.o

# ---------------------------------------------------------------------------- #
# ====> COMMANDS AND FLAGS                                                     #
# ---------------------------------------------------------------------------- #

INCS		= $(addprefix -I, $(PATH_INCS))

CC			= clang
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f
RMR			= rm -rf

LFTFLAGS	= -L$(PATH_LFT) -lft
LTESTFLAGS	= -L$(PATH_TEST) -ltest

FSAN		= -g3 -fsanitize=address

# ---------------------------------------------------------------------------- #
# ====> BINARY NAMES                                                           #
# ---------------------------------------------------------------------------- #

NAME		= push_swap

# ---------------------------------------------------------------------------- #
# ====> FUNCTIONS                                                              #
# ---------------------------------------------------------------------------- #

### Compile rule for .c files in srcs
$(PATH_OBJS)%.o: $(PATH_SRCS)%.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

### Compile rule for .c files in tests
$(PATH_OBJS)%.o: $(PATH_TEST)%.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

### "make" default rule call
$(NAME): $(PATH_OBJS) $(OBJS) $(MAIN_BIN)
	@make -C $(PATH_LFT)
	$(CC) $(CFLAGS) $(OBJS) $(MAIN_BIN) -o $(NAME) $(LFTFLAGS)

### Objects folder generation rule
$(PATH_OBJS):
	@mkdir $(PATH_OBJS)

### FSanitize compile rule, will need fclean afterwards
fsan: $(PATH_OBJS) $(OBJS) $(MAIN_BIN)
	@make -C $(PATH_LFT)
	$(CC) $(CFLAGS) $(FSAN) $(OBJS) $(MAIN_BIN) -o $(NAME) $(LFTFLAGS)

### Leaks verification through valgrind
leaks: $(NAME)
	valgrind --tool=memcheck --leak-check=full --leak-resolution=high \
	--show-reachable=yes --track-origins=yes ./$(NAME)

### Test compilation rule
# test: $(PATH_OBJS) $(OBJS) $(OBJS_TEST) $(T_MAIN_BIN)
#	@make -C $(PATH_LFT)
#	@make -C $(PATH_TEST)
#	$(CC) $(CFLAGS) $(OBJS) $(OBJS_TEST) $(T_MAIN_BIN) -o $(NAME) $(LFTFLAGS) \
#	$(LTESTFLAGS)

### Standard rules
all: $(NAME)

clean:
	$(RMR) $(PATH_OBJS)
	@make clean -C $(PATH_LFT)
#	@make clean -C $(PATH_TEST)

fclean: clean
	$(RM) $(NAME) $(BIN) run.sh
	$(RMR) $(NAME).dSYM
	@make fclean -C $(PATH_LFT)
#	@make fclean -C $(PATH_TEST)

re: fclean all

# ---------------------------------------------------------------------------- #
# ====> PHONY DEFINITION                                                       #
# ---------------------------------------------------------------------------- #

.PHONY: all clean fclean re test

