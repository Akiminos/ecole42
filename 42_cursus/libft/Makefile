F_SRCS		= ./

F_INCLUDES	= ./

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
			  $(F_SRCS)ft_putendl_fd.c $(F_SRCS)ft_putnbr_fd.c

SRCS_BONUS	= $(F_SRCS)ft_lstnew_bonus.c $(F_SRCS)ft_lstadd_front_bonus.c \
			  $(F_SRCS)ft_lstsize_bonus.c $(F_SRCS)ft_lstlast_bonus.c \
			  $(F_SRCS)ft_lstadd_back_bonus.c $(F_SRCS)ft_lstdelone_bonus.c \
			  $(F_SRCS)ft_lstiter_bonus.c $(F_SRCS)ft_lstclear_bonus.c \
			  $(F_SRCS)ft_lstmap_bonus.c

INCLUDES	= -I$(F_INCLUDES)

OBJS		= $(SRCS:.c=.o)

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

CC			= gcc
RM			= rm -f
LIB			= ar -rcs

CFLAGS		= -Wall -Wextra -Werror
LIBFLAGS	= -L. -lft

NAME		= libft.a

BIN			= libft

BONUS		= bonus

BIN_BONUS	= libft_bonus

.c.o:
				$(CC) $(CFLAGS) -c $<  -o $(<:.c=.o) $(INCLUDES)

$(NAME):		$(OBJS)
				$(LIB) $(NAME) $(OBJS)

$(BIN):			$(NAME) main.c
				$(CC) $(CFlAGS) main.c -o $(BIN) $(LIBFLAGS) $(INCLUDES)

$(BONUS):		$(OBJS) $(OBJS_BONUS)
				$(LIB) $(NAME) $(OBJS) $(OBJS_BONUS)

$(BIN_BONUS):	$(BONUS) main.c
				$(CC) $(CFLAGS) main.c -o $(BIN_BONUS) $(LIBFLAGS) $(INCLUDES)

all:			$(NAME)

clean:
				$(RM) $(OBJS) $(OBJS_BONUS)

fclean:			clean
				$(RM) $(NAME) $(BIN) $(BIN_BONUS)

re:				fclean all

.PHONY:			all clean fclean re
