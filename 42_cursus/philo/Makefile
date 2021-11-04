# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 12:02:20 by bdruez            #+#    #+#              #
#    Updated: 2021/11/04 19:18:06 by bdruez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
# ====> PATHS                                                                  #
# ---------------------------------------------------------------------------- #

PATH_SRCS		= ./srcs/
PATH_INCS		= ./includes/ \

PATH_OBJS		= ./objs/

PATH_TEST		= ./tests/
TEST_PREFIX		= test_

# ---------------------------------------------------------------------------- #
# ====> FILES                                                                  #
# ---------------------------------------------------------------------------- #

F_SRCS		= check_death.c \
			  get_time_diff.c \
			  lock_forks.c \
			  parser.c \
			  philos.c \
			  routine.c \
			  run.c \
			  status.c \
			  status_2.c \
			  t_fork.c \
			  t_info.c \
			  t_param.c \
			  t_philo.c \
			  utils.c \

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
CFLAGS		= -Wall -Wextra -Werror -pthread

RM			= rm -f
RMR			= rm -rf

LTESTFLAGS	= -L$(PATH_TEST) -ltest

FSAN		= -g3 -fsanitize=thread

# ---------------------------------------------------------------------------- #
# ====> BINARY NAMES                                                           #
# ---------------------------------------------------------------------------- #

NAME		= philo

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
	$(CC) $(CFLAGS) $(OBJS) $(MAIN_BIN) -o $(NAME)

### Objects folder generation rule
$(PATH_OBJS):
	@mkdir $(PATH_OBJS)

### FSanitize compile rule, will need fclean afterwards
fsan: $(PATH_OBJS) $(OBJS) $(MAIN_BIN)
	$(CC) $(CFLAGS) $(FSAN) $(OBJS) $(MAIN_BIN) -o $(NAME)

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
#	@make clean -C $(PATH_TEST)

fclean: clean
	$(RM) $(NAME) $(BIN) run.sh
	$(RMR) $(NAME).dSYM
#	@make fclean -C $(PATH_TEST)

re: fclean all

# ---------------------------------------------------------------------------- #
# ====> PHONY DEFINITION                                                       #
# ---------------------------------------------------------------------------- #

.PHONY: all clean fclean re test leaks fsan

