# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/04 10:29:39 by bdruez            #+#    #+#              #
#    Updated: 2020/03/10 13:41:44 by bdruez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
# ====> PATHS                                                                  #
# ---------------------------------------------------------------------------- #

### ft_printf
F_SRCS			= ./
F_SRCS_TESTS	= $(F_SRCS)tests/
F_INCLUDES		= ./

### libft
F_LFT			= ./libft/
F_LFT_SRCS		= $(F_LFT)srcs/
F_LFT_INCLUDES	= $(F_LFT)includes/

# ---------------------------------------------------------------------------- #
# ====> FILES                                                                  #
# ---------------------------------------------------------------------------- #

SRCS			= $(F_SRCS)ft_printf.c $(F_SRCS)ft_printf_utils.c \
				  $(F_SRCS)display_c.c $(F_SRCS)display_id.c \
				  $(F_SRCS)display_s.c $(F_SRCS)display_x.c \
				  $(F_SRCS)display_p.c $(F_SRCS)display_u.c \
				  $(F_SRCS)t_data.c $(F_SRCS)length_utils.c \
				  $(F_SRCS)display_wrong.c $(F_SRCS)display_id_printing.c \
				  $(F_SRCS)display_u_printing.c $(F_SRCS)display_x_printing.c

LFT_SRCS		= $(F_LFT_SRCS)ft_strlen.c $(F_LFT_SRCS)ft_isalpha.c \
				  $(F_LFT_SRCS)ft_isdigit.c $(F_LFT_SRCS)ft_isalnum.c \
				  $(F_LFT_SRCS)ft_isascii.c $(F_LFT_SRCS)ft_isprint.c \
				  $(F_LFT_SRCS)ft_toupper.c $(F_LFT_SRCS)ft_tolower.c \
				  $(F_LFT_SRCS)ft_strchr.c $(F_LFT_SRCS)ft_strrchr.c \
				  $(F_LFT_SRCS)ft_strncmp.c $(F_LFT_SRCS)ft_strlcpy.c \
				  $(F_LFT_SRCS)ft_strlcat.c $(F_LFT_SRCS)ft_strnstr.c \
				  $(F_LFT_SRCS)ft_isspace.c $(F_LFT_SRCS)ft_atoi.c \
				  $(F_LFT_SRCS)ft_memset.c $(F_LFT_SRCS)ft_bzero.c \
				  $(F_LFT_SRCS)ft_memcpy.c $(F_LFT_SRCS)ft_memccpy.c \
				  $(F_LFT_SRCS)ft_memmove.c $(F_LFT_SRCS)ft_memchr.c \
				  $(F_LFT_SRCS)ft_memcmp.c $(F_LFT_SRCS)ft_strdup.c \
				  $(F_LFT_SRCS)ft_calloc.c $(F_LFT_SRCS)ft_substr.c \
				  $(F_LFT_SRCS)ft_strjoin.c $(F_LFT_SRCS)ft_strtrim.c \
				  $(F_LFT_SRCS)ft_itoa.c $(F_LFT_SRCS)ft_strndup.c \
				  $(F_LFT_SRCS)ft_split.c $(F_LFT_SRCS)ft_strmapi.c \
				  $(F_LFT_SRCS)ft_putchar_fd.c $(F_LFT_SRCS)ft_putstr_fd.c \
				  $(F_LFT_SRCS)ft_putendl_fd.c $(F_LFT_SRCS)ft_putnbr_fd.c \
				  $(F_LFT_SRCS)ft_putstrn_fd.c $(F_LFT_SRCS)ft_putnbr_hex_fd.c \
				  $(F_LFT_SRCS)ft_twos_complement.c \
				  $(F_LFT_SRCS)ft_lstnew.c $(F_LFT_SRCS)ft_lstadd_front.c \
				  $(F_LFT_SRCS)ft_lstsize.c $(F_LFT_SRCS)ft_lstlast.c \
				  $(F_LFT_SRCS)ft_lstadd_back.c $(F_LFT_SRCS)ft_lstdelone.c \
				  $(F_LFT_SRCS)ft_lstiter.c $(F_LFT_SRCS)ft_lstclear.c \
				  $(F_LFT_SRCS)ft_lstmap.c $(F_LFT_SRCS)ft_putnbr_uint_fd.c \
				  $(F_LFT_SRCS)ft_min.c $(F_LFT_SRCS)ft_max.c

SRCS_TESTS		= $(F_SRCS_TESTS)test_ft_get_data_info.c

MAIN			= $(F_SRCS)main.c
MAIN_TESTS		= $(F_SRCS_TESTS)test_main.c

OBJS			= $(SRCS:.c=.o)
OBJS_LIBFT		= $(LFT_SRCS:.c=.o)
OBJS_TESTS		= $(SRCS_TESTS:.c=.o)

# ---------------------------------------------------------------------------- #
# ====> FLAGS                                                                  #
# ---------------------------------------------------------------------------- #

INCLUDES		= -I$(F_INCLUDES) -I$(F_LFT_INCLUDES)

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

.c.o:
					$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(INCLUDES)

### Static library compilation
$(NAME):			$(OBJS) $(OBJS_LIBFT)
					$(LIB) $(NAME) $(OBJS) $(OBJS_LIBFT)

### Standard binaries compilation
$(BIN):				$(NAME) $(MAIN)
					$(CC) $(CFLAGS) $(MAIN) -o $(BIN) $(LIBFLAGS) $(INCLUDES)

$(BIN_FSANITIZE):	$(NAME) $(MAIN)
					$(CC) $(CFLAGS) $(MAIN) $(FSANITIZE) -o $(BIN_FSANITIZE) \
					$(LIBFLAGS) $(INCLUDES)

### Testing binaries compilation
$(TESTS):			$(NAME) $(MAIN_TESTS) $(OBJS_TESTS)
					$(CC) $(CFLAGS) $(MAIN_TESTS) $(OBJS_TESTS) -o $(TESTS) \
					$(LIBFLAGS) $(INCLUDES)

$(TESTS_FSANITIZE):	$(NAME) $(MAIN_TESTS) $(OBJS_TESTS)
					$(CC) $(CFLAGS) $(FSANITIZE) $(MAIN_TESTS) $(OBJS_TESTS) \
					-o $(TESTS_FSANITIZE) $(LIBFLAGS) $(INCLUDES)

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
					norminette $(LFT_SRCS) $(SRCS) $(F_LFT_INCLUDES) \
					$(F_INCLUDES)

.PHONY:				all clean fclean re norminette
