# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/04 10:38:33 by bdruez            #+#    #+#              #
#    Updated: 2021/02/02 21:38:18 by bdruez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
# ====> PATHS                                                                  #
# ---------------------------------------------------------------------------- #

PATH_SRCS		= ./srcs/
PATH_INCS		= ./includes/ ./libft/includes/
PATH_OBJS		= ./objs/
PATH_LFT		= ./libft/

PATH_TEST		= ./tests/
TEST_PREF		= test_

# ---------------------------------------------------------------------------- #
# ====> FILES                                                                  #
# ---------------------------------------------------------------------------- #

F_SRCS		= main.c input.c parser.c t_data.c

# ---------------------------------------------------------------------------- #
# ====> VARIABLES                                                              #
# ---------------------------------------------------------------------------- #

SRCS		= $(addprefix $(PATH_SRCS), $(F_SRCS))
OBJS		= $(addprefix $(PATH_OBJS), $(F_SRCS:.c=.o))
TEST		= $(addprefix $(PATH_TEST)$(

# ---------------------------------------------------------------------------- #
# ====> COMMANDS AND FLAGS                                                     #
# ---------------------------------------------------------------------------- #

INCS		= $(addprefix -I, $(PATH_INCS))

CC			= clang
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f
RMR			= rm -rf

LFTFLAGS	= -L$(PATH_LFT) -lft

FSAN		= -g3 -fsanitize=address

# ---------------------------------------------------------------------------- #
# ====> BINARY NAMES                                                           #
# ---------------------------------------------------------------------------- #

NAME		= cube3d

# ---------------------------------------------------------------------------- #
# ====> FUNCTIONS                                                              #
# ---------------------------------------------------------------------------- #

### Compile rule for .c files
$(PATH_OBJS)%.o: $(PATH_SRCS)%.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

### "make" default rule call
$(NAME): $(PATH_OBJS) $(OBJS)
	@make -C $(PATH_LFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LFTFLAGS)

### Objects folder generation rule
$(PATH_OBJS):
	@mkdir $(PATH_OBJS)

### FSanitize compile rule, will need fclean afterwards
fsan: $(PATH_OBJS) $(OBJS)
	@make -C $(PATH_LFT)
	$(CC) $(CFLAGS) $(FSAN) $(OBJS) -o $(NAME) $(LFTFLAGS)

### Leaks verification through valgrind
leaks: $(NAME)
	valgrind --tool=memcheck --leak-check=full --leak-resolution=high \
	--show-reachable=yes --track-origins=yes ./$(NAME)

### Standard rules
all: $(NAME)

clean:
	$(RMR) $(PATH_OBJS)
	@make clean -C $(PATH_LFT)

fclean: clean
	$(RM) $(NAME) $(BIN)
	@make fclean -C $(PATH_LFT)

re: fclean all

# ---------------------------------------------------------------------------- #
# ====> PHONY DEFINITION                                                       #
# ---------------------------------------------------------------------------- #

.PHONY: all clean fclean re

