# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/04 10:38:33 by bdruez            #+#    #+#              #
#    Updated: 2020/01/21 17:11:16 by bdruez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----- PATHS ---------------------------------------------------------------- #

F_SRCS		= ./srcs/
F_INCLUDES	= ./includes/

# ----- FILES ---------------------------------------------------------------- #

SRCS		= $(F_SRCS)ft_strlen.c $(F_SRCS)ft_isalpha.c $(F_SRCS)ft_isdigit.c \
			  $(F_SRCS)ft_isalnum.c $(F_SRCS)ft_isascii.c $(F_SRCS)ft_isprint.c\
			  $(F_SRCS)ft_toupper.c $(F_SRCS)ft_tolower.c $(F_SRCS)ft_strchr.c \
			  $(F_SRCS)ft_strrchr.c $(F_SRCS)ft_strncmp.c $(F_SRCS)ft_strlcpy.c\
			  $(F_SRCS)ft_strlcat.c $(F_SRCS)ft_strnstr.c $(F_SRCS)ft_isspace.c\
			  $(F_SRCS)ft_atoi.c $(F_SRCS)ft_memset.c $(F_SRCS)ft_bzero.c \
			  $(F_SRCS)ft_memcpy.c $(F_SRCS)ft_memccpy.c $(F_SRCS)ft_memmove.c \
			  $(F_SRCS)ft_memchr.c $(F_SRCS)ft_memcmp.c $(F_SRCS)ft_strdup.c \
			  $(F_SRCS)ft_calloc.c $(F_SRCS)ft_substr.c $(F_SRCS)ft_strjoin.c \
			  $(F_SRCS)ft_strtrim.c $(F_SRCS)ft_itoa.c $(F_SRCS)ft_strndup.c \
			  $(F_SRCS)ft_split.c $(F_SRCS)ft_strmapi.c \
			  $(F_SRCS)ft_putchar_fd.c $(F_SRCS)ft_putstr_fd.c \
			  $(F_SRCS)ft_putendl_fd.c $(F_SRCS)ft_putnbr_fd.c \
			  $(F_SRCS)ft_putstr_fd.c $(F_SRCS)ft_putnbr_hex_fd.c \
			  $(F_SRCS)ft_lstnew.c $(F_SRCS)ft_lstadd_front.c \
			  $(F_SRCS)ft_lstsize.c $(F_SRCS)ft_lstlast.c \
			  $(F_SRCS)ft_lstadd_back.c $(F_SRCS)ft_lstdelone.c \
			  $(F_SRCS)ft_lstiter.c $(F_SRCS)ft_lstclear.c \
			  $(F_SRCS)ft_lstmap.c $(F_SRCS)ft_min.c $(F_SRCS)ft_max.c \
			  $(F_SRCS)ft_putnbr_uint_fd.c

OBJS		= $(SRCS:.c=.o)

# ----- FLAGS ---------------------------------------------------------------- #

INCLUDES	= -I$(F_INCLUDES)

CC			= gcc
RM			= rm -f
LIB			= ar -rcs
CFLAGS		= -Wall -Wextra -Werror
LIBFLAGS	= -L. -lft

# ----- BINARY NAMES --------------------------------------------------------- #

NAME		= libft.a

OBJECTS		= objects

# BIN_NAME	= libft

# ----- FUNCTIONS ------------------------------------------------------------ #

.c.o:
				$(CC) $(CFLAGS) -c $<  -o $(<:.c=.o) $(INCLUDES)

$(OBJECTS):		$(OBJS)

$(NAME):		$(OBJS)
				$(LIB) $(NAME) $(OBJS)

# $(BIN_NAME):	$(NAME) main.c
#				$(CC) $(CFlAGS) main.c -o $(BIN_NAME) $(LIBFLAGS) $(INCLUDES)

all:			$(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME) $(BIN)

re:				fclean all

.PHONY:			all clean fclean re
