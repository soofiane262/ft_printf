NAME	=	libftprintf.a

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

AR		=	ar rc

SRCS	=	ft_printf.c ft_printf_utils.c

OBJS	=	$(SRCS:.c=.o)

HDFL	=	ft_printf.h

all: $(NAME)

$(NAME): $(OBJS) $(HDFL)
	@$(CC) $(CFLAGS) -c $(SRCS) -I $(HDFL)
	@$(AR) $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re