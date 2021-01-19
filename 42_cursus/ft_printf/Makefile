# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/04 10:29:39 by bdruez            #+#    #+#              #
#    Updated: 2021/01/19 13:27:10 by bdruez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
# ====> PATHS                                                                  #
# ---------------------------------------------------------------------------- #

### ft_printf
D_SRCS			= ./
D_SRCS_TESTS	= $(D_SRCS)tests/
D_INCS		= ./

### libft
D_LFT			= ./libft/
D_LFT_SRCS		= $(D_LFT)srcs/
D_LFT_INCS	= $(D_LFT)includes/

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

LFT_SRCS		= $(D_LFT_SRCS)ft_strlen.c $(D_LFT_SRCS)ft_isalpha.c \
				  $(D_LFT_SRCS)ft_isdigit.c $(D_LFT_SRCS)ft_isalnum.c \
				  $(D_LFT_SRCS)ft_isascii.c $(D_LFT_SRCS)ft_isprint.c \
				  $(D_LFT_SRCS)ft_toupper.c $(D_LFT_SRCS)ft_tolower.c \
				  $(D_LFT_SRCS)ft_strchr.c $(D_LFT_SRCS)ft_strrchr.c \
				  $(D_LFT_SRCS)ft_strncmp.c $(D_LFT_SRCS)ft_strlcpy.c \
				  $(D_LFT_SRCS)ft_strlcat.c $(D_LFT_SRCS)ft_strnstr.c \
				  $(D_LFT_SRCS)ft_isspace.c $(D_LFT_SRCS)ft_atoi.c \
				  $(D_LFT_SRCS)ft_memset.c $(D_LFT_SRCS)ft_bzero.c \
				  $(D_LFT_SRCS)ft_memcpy.c $(D_LFT_SRCS)ft_memccpy.c \
				  $(D_LFT_SRCS)ft_memmove.c $(D_LFT_SRCS)ft_memchr.c \
				  $(D_LFT_SRCS)ft_memcmp.c $(D_LFT_SRCS)ft_strdup.c \
				  $(D_LFT_SRCS)ft_calloc.c $(D_LFT_SRCS)ft_substr.c \
				  $(D_LFT_SRCS)ft_strjoin.c $(D_LFT_SRCS)ft_strtrim.c \
				  $(D_LFT_SRCS)ft_itoa.c $(D_LFT_SRCS)ft_strndup.c \
				  $(D_LFT_SRCS)ft_split.c $(D_LFT_SRCS)ft_strmapi.c \
				  $(D_LFT_SRCS)ft_putchar_fd.c $(D_LFT_SRCS)ft_putstr_fd.c \
				  $(D_LFT_SRCS)ft_putendl_fd.c $(D_LFT_SRCS)ft_putnbr_fd.c \
				  $(D_LFT_SRCS)ft_putstrn_fd.c $(D_LFT_SRCS)ft_putnbr_hex_fd.c \
				  $(D_LFT_SRCS)ft_twos_complement.c \
				  $(D_LFT_SRCS)ft_lstnew.c $(D_LFT_SRCS)ft_lstadd_front.c \
				  $(D_LFT_SRCS)ft_lstsize.c $(D_LFT_SRCS)ft_lstlast.c \
				  $(D_LFT_SRCS)ft_lstadd_back.c $(D_LFT_SRCS)ft_lstdelone.c \
				  $(D_LFT_SRCS)ft_lstiter.c $(D_LFT_SRCS)ft_lstclear.c \
				  $(D_LFT_SRCS)ft_lstmap.c $(D_LFT_SRCS)ft_putnbr_uint_fd.c \
				  $(D_LFT_SRCS)ft_min.c $(D_LFT_SRCS)ft_max.c

SRCS_TESTS		= $(D_SRCS_TESTS)test_ft_get_data_info.c

MAIN			= $(D_SRCS)main.c
MAIN_TESTS		= $(D_SRCS_TESTS)test_main.c

OBJS			= $(SRCS:.c=.o)
OBJS_LIBFT		= $(LFT_SRCS:.c=.o)
OBJS_TESTS		= $(SRCS_TESTS:.c=.o)

# ---------------------------------------------------------------------------- #
# ====> FLAGS                                                                  #
# ---------------------------------------------------------------------------- #

INCS		= -I$(D_INCS) -I$(D_LFT_INCS)

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
FSANITIZE		= -g3 -fsanitize=address
LIB				= ar -rvs
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
%.o	: %.c	Makefile
					$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

#.c.o:
#					$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(INCS)

### Static library compilation
$(NAME):			$(OBJS) $(OBJS_LIBFT)
					$(LIB) $(NAME) $(OBJS) $(OBJS_LIBFT)

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

fclean:				clean
					$(RM) $(NAME) $(NAME_FSANITIZE) $(BIN) $(BIN_FSANITIZE) \
					$(TESTS) $(TESTS_FSANITIZE)
					$(RMR) $(NAME_FSANITIZE).dSYM $(TESTS_FSANITIZE).dSYM 

re:					fclean all

norminette:
					norminette $(LFT_SRCS) $(SRCS) $(D_LFT_INCS) \
					$(D_INCS)

.PHONY:				all clean fclean re norminette
