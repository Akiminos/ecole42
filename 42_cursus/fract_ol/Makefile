# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/28 17:29:30 by bdruez            #+#    #+#              #
#    Updated: 2021/09/16 22:47:20 by bdruez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
# ====> PATHS                                                                  #
# ---------------------------------------------------------------------------- #

PATH_SRCS		= ./srcs/
PATH_INCS		= ./includes/ ./libft/includes/ ./tests/includes/ \
				  ./minilibx-linux
PATH_OBJS		= ./objs/
PATH_LFT		= ./libft/
PATH_LMLX		= ./minilibx-linux/

PATH_TEST		= ./tests/
TEST_PREFIX		= test_

# ---------------------------------------------------------------------------- #
# ====> FILES                                                                  #
# ---------------------------------------------------------------------------- #

F_SRCS		= color_convert.c \
			  draw.c \
			  exit_management.c \
			  hook.c \
			  hsv_to_trgb.c \
			  image.c \
			  julia.c \
			  key_zoom.c \
			  key_move.c \
			  mandelbrot.c \
			  mouse_zoom.c \
			  parse.c \
			  pixel.c \
			  t_color.c \
			  t_complex.c \
			  t_data.c \
			  t_image.c \
			  t_view.c \
			  window.c \

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
LMLXFLAGS	= -L$(PATH_LMLX) -lmlx -lXext -lX11
LMLXLFLAGS	= -L$(PATH_LMLX) -lmlx_Linux -lXext -lX11
LIBS		= $(LFTFLAGS) $(LMLXFLAGS) $(LMLXLFLAGS) 

LTESTFLAGS	= -L$(PATH_TEST) -ltest

FSAN		= -g3 -fsanitize=address

# ---------------------------------------------------------------------------- #
# ====> BINARY NAMES                                                           #
# ---------------------------------------------------------------------------- #

NAME		= fractol

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
	@make -C $(PATH_LMLX)
	$(CC) $(CFLAGS) $(OBJS) $(MAIN_BIN) -o $(NAME) $(LIBS) -lm

### Objects folder generation rule
$(PATH_OBJS):
	@mkdir $(PATH_OBJS)

### FSanitize compile rule, will need fclean afterwards
fsan: $(PATH_OBJS) $(OBJS) $(MAIN_BIN)
	@make -C $(PATH_LFT)
	@make -C $(PATH_LMLX)
	$(CC) $(CFLAGS) $(FSAN) $(OBJS) $(MAIN_BIN) -o $(NAME) $(LIBS) -lm

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
	@make clean -C $(PATH_LMLX)
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

