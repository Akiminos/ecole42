# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/04 10:29:39 by bdruez            #+#    #+#              #
#    Updated: 2021/01/19 16:59:17 by bdruez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
# ====> PATHS                                                                  #
# ---------------------------------------------------------------------------- #

### ft_printf
D_SRCS			= ./
D_SRCS_TESTS	= $(D_SRCS)tests/
D_INCS			= ./

### libft
D_LFT			= ./libft/
D_LFT_INCS		= ./libft/includes/
D_LFT_SRCS		= ./libft/srcs/

# ---------------------------------------------------------------------------- #
# ====> FILES                                                                  #
# ---------------------------------------------------------------------------- #

SRCS			= $(D_SRCS)ft_printf.c $(D_SRCS)ft_printf_utils.c \
				  $(D_SRCS)display_c.c $(D_SRCS)display_id.c \
				  $(D_SRCS)display_s.c $(D_SRCS)display_x.c \
				  $(D_SRCS)display_p.c $(D_SRCS)display_u.c \
				  $(D_SRCS)t_data.c $(D_SRCS)length_utils.c \
				  $(D_SRCS)display_wrong.c $(D_SRCS)display_id_printing.c \
				  $(D_SRCS)display_u_printing.c $(D_SRCS)display_x_printing.c

SRCS_TESTS		= $(D_SRCS_TESTS)test_ft_get_data_info.c

LFT				= $(D_LFT)libft.a

MAIN			= $(D_SRCS)main.c
MAIN_TESTS		= $(D_SRCS_TESTS)test_main.c

HEAD			= $(D_INCS)ft_printf.h

OBJS			= $(SRCS:.c=.o)
OBJS_TESTS		= $(SRCS_TESTS:.c=.o)

# ---------------------------------------------------------------------------- #
# ====> FLAGS AND COMMANDS                                                     #
# ---------------------------------------------------------------------------- #

INCS			= -I$(D_INCS) -I$(D_LFT_INCS)

CC				= clang
CFLAGS			= -Wall -Wextra -Werror
FSANITIZE		= -g3 -fsanitize=address
LIB				= ar -rcs
LIBFLAGS		= -L. -lftprintf
RM				= rm -f
RMR				= rm -rf # For fsanitize .dSYM folder cleaning

# ---------------------------------------------------------------------------- #
# ====> BINARY NAMES                                                           #
# ---------------------------------------------------------------------------- #

NAME			= libftprintf.a

BIN				= ftprintf
BIN_FSANITIZE	= ftprintf_fsanitize

TESTS			= test
TESTS_FSANITIZE	= test_fsanitize

BONUS			= bonus

# ---------------------------------------------------------------------------- #
# ====> FUNCTIONS                                                              #
# ---------------------------------------------------------------------------- #

### Compile rule for .c files
%.o	: %.c			Makefile
					$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

### Static library compilation
$(NAME):			$(OBJS) $(HEAD)
					@make -C $(D_LFT)
					$(LIB) $(NAME) $(OBJS) $(D_LFT_SRCS)*.o

### Standard binaries compilation
$(BIN):				$(NAME) $(MAIN)
					$(CC) $(CFLAGS) $(MAIN) -o $(BIN) $(LIBFLAGS) $(INCS)

$(BIN_FSANITIZE):	$(NAME) $(MAIN)
					$(CC) $(CFLAGS) $(MAIN) $(FSANITIZE) -o $(BIN_FSANITIZE) \
					$(LIBFLAGS) $(INCS)

### Testing binaries compilation
$(TESTS):			$(NAME) $(MAIN_TESTS) $(OBJS_TESTS)
					$(CC) $(CFLAGS) $(MAIN_TESTS) $(OBJS_TESTS) -o $(TESTS) \
					$(LIBFLAGS) $(INCS)

$(TESTS_FSANITIZE):	$(NAME) $(MAIN_TESTS) $(OBJS_TESTS)
					$(CC) $(CFLAGS) $(FSANITIZE) $(MAIN_TESTS) $(OBJS_TESTS) \
					-o $(TESTS_FSANITIZE) $(LIBFLAGS) $(INCS)

### General rules
all:				$(NAME)

clean:
					$(RM) $(OBJS) $(OBJS_LIBFT) $(OBJS_TESTS)
					@make clean -C $(D_LFT)

fclean:				clean
					$(RM) $(NAME) $(NAME_FSANITIZE) $(BIN) $(BIN_FSANITIZE) \
					$(TESTS) $(TESTS_FSANITIZE)
					$(RMR) $(NAME_FSANITIZE).dSYM $(TESTS_FSANITIZE).dSYM 
					@make fclean -C $(D_LFT)

re:					fclean all

norminette:
					norminette $(LFT_SRCS) $(SRCS) $(D_LFT_INCS) \
					$(D_INCS)

.PHONY:				all clean fclean re norminette
