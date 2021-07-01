# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/04 10:38:33 by bdruez            #+#    #+#              #
#    Updated: 2021/02/17 12:52:25 by bdruez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
# ====> PATHS                                                                  #
# ---------------------------------------------------------------------------- #

PATH_SRCS	= ./srcs/
PATH_INCS	= ./includes/
PATH_OBJS	= ./objs/

# ---------------------------------------------------------------------------- #
# ====> FILES                                                                  #
# ---------------------------------------------------------------------------- #

F_SRCS		= ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			  ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
			  ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_isspace.c \
			  ft_atoi.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
			  ft_memmove.c ft_memchr.c ft_memcmp.c ft_strdup.c ft_calloc.c \
			  ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strndup.c \
			  ft_split.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
			  ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_putnbr_hex_fd.c \
			  ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			  ft_lstadd_back.c ft_lstdelone.c ft_lstiter.c ft_lstclear.c \
			  ft_lstmap.c ft_min.c ft_max.c ft_putnbr_uint_fd.c ft_strreftrim.c

F_INCS		= libft.h

# ---------------------------------------------------------------------------- #
# ====> VARIABLES                                                              #
# ---------------------------------------------------------------------------- #

SRCS		= $(addprefix $(PATH_SRCS), $(F_SRCS))
HEAD		= $(addprefix $(PATH_INCS), $(F_INCS))
OBJS		= $(addprefix $(PATH_OBJS), $(F_SRCS:.c=.o))

# ---------------------------------------------------------------------------- #
# ====> FLAGS                                                                  #
# ---------------------------------------------------------------------------- #

INCS	= $(addprefix -I, $(PATH_INCS))

CC			= clang
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f
RMR			= rm -rf

LIB			= ar -rcs
LIBFLAGS	= -L. -lft

# ---------------------------------------------------------------------------- #
# ====> BINARY NAMES                                                           #
# ---------------------------------------------------------------------------- #

NAME		= libft.a

# ---------------------------------------------------------------------------- #
# ====> FUNCTIONS                                                              #
# ---------------------------------------------------------------------------- #

### Compile rule for .c files
$(PATH_OBJS)%.o: $(PATH_SRCS)%.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

### "make" default rule call
$(NAME): $(PATH_OBJS) $(OBJS)
	$(LIB) $(NAME) $(OBJS)

### objects folder generation rule (non-phony)
$(PATH_OBJS):
	@mkdir $(PATH_OBJS)

all: $(NAME)

clean:
	$(RMR) $(PATH_OBJS)

fclean: clean
	$(RM) $(NAME) $(BIN)

re: fclean all

# ---------------------------------------------------------------------------- #
# ====> PHONY DEFINITION                                                       #
# ---------------------------------------------------------------------------- #

.PHONY: all clean fclean re

