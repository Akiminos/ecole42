# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/04 10:38:33 by bdruez            #+#    #+#              #
#    Updated: 2021/01/19 14:07:27 by bdruez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
# ====> PATHS                                                                  #
# ---------------------------------------------------------------------------- #

D_SRCS	= ./srcs/
D_INCS	= ./includes/

# ---------------------------------------------------------------------------- #
# ====> FILES                                                                  #
# ---------------------------------------------------------------------------- #

SRCS		= $(D_SRCS)ft_strlen.c $(D_SRCS)ft_isalpha.c $(D_SRCS)ft_isdigit.c \
			  $(D_SRCS)ft_isalnum.c $(D_SRCS)ft_isascii.c $(D_SRCS)ft_isprint.c\
			  $(D_SRCS)ft_toupper.c $(D_SRCS)ft_tolower.c $(D_SRCS)ft_strchr.c \
			  $(D_SRCS)ft_strrchr.c $(D_SRCS)ft_strncmp.c $(D_SRCS)ft_strlcpy.c\
			  $(D_SRCS)ft_strlcat.c $(D_SRCS)ft_strnstr.c $(D_SRCS)ft_isspace.c\
			  $(D_SRCS)ft_atoi.c $(D_SRCS)ft_memset.c $(D_SRCS)ft_bzero.c \
			  $(D_SRCS)ft_memcpy.c $(D_SRCS)ft_memccpy.c $(D_SRCS)ft_memmove.c \
			  $(D_SRCS)ft_memchr.c $(D_SRCS)ft_memcmp.c $(D_SRCS)ft_strdup.c \
			  $(D_SRCS)ft_calloc.c $(D_SRCS)ft_substr.c $(D_SRCS)ft_strjoin.c \
			  $(D_SRCS)ft_strtrim.c $(D_SRCS)ft_itoa.c $(D_SRCS)ft_strndup.c \
			  $(D_SRCS)ft_split.c $(D_SRCS)ft_strmapi.c \
			  $(D_SRCS)ft_putchar_fd.c $(D_SRCS)ft_putstr_fd.c \
			  $(D_SRCS)ft_putendl_fd.c $(D_SRCS)ft_putnbr_fd.c \
			  $(D_SRCS)ft_putstr_fd.c $(D_SRCS)ft_putnbr_hex_fd.c \
			  $(D_SRCS)ft_lstnew.c $(D_SRCS)ft_lstadd_front.c \
			  $(D_SRCS)ft_lstsize.c $(D_SRCS)ft_lstlast.c \
			  $(D_SRCS)ft_lstadd_back.c $(D_SRCS)ft_lstdelone.c \
			  $(D_SRCS)ft_lstiter.c $(D_SRCS)ft_lstclear.c \
			  $(D_SRCS)ft_lstmap.c $(D_SRCS)ft_min.c $(D_SRCS)ft_max.c \
			  $(D_SRCS)ft_putnbr_uint_fd.c

OBJS		= $(SRCS:.c=.o)

# ---------------------------------------------------------------------------- #
# ====> FLAGS                                                                  #
# ---------------------------------------------------------------------------- #

INCS	= -I$(D_INCS)

CC			= gcc
RM			= rm -f
LIB			= ar -rcs
CFLAGS		= -Wall -Wextra -Werror
LIBFLAGS	= -L. -lft

# ---------------------------------------------------------------------------- #
# ====> BINARY NAMES                                                           #
# ---------------------------------------------------------------------------- #

NAME		= libft.a

# ---------------------------------------------------------------------------- #
# ====> FUNCTIONS                                                              #
# ---------------------------------------------------------------------------- #

### Compile rule for .c files
%.o	: %.c	Makefile
				$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(NAME):		$(OBJS)
				$(LIB) $(NAME) $(OBJS)

all:			$(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME) $(BIN)

re:				fclean all

.PHONY:			all clean fclean re
