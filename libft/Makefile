CC		=	cc
AR		=	ar
ARFLAGS	=	crs
CFLAGS	=	-Wall -Wextra -Werror

NAME 	= 	libft.a

SRCS	=	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
		 	ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_printf/ft_printf.c \
			ft_printf/putnbr_printf.c \
			ft_printf/print_char.c \
			ft_printf/print_dec.c \
			ft_printf/print_hex.c \
			ft_printf/print_int.c \
			ft_printf/print_ptr.c \
			ft_printf/print_str.c \
			ft_printf/print_uint.c \
			ft_printf/printf_utils.c \
			ft_printf/printf_utils2.c \
			ft_printf/printf_utils3.c \
			ft_printf/putaddress.c \
			ft_printf/puthex.c \
			ft_printf/putuint.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

.PHONY: all
all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean :
	rm -f $(OBJS)

.PHONY: fclean
fclean : clean
	rm -f $(NAME)

.PHONY: re
re :
	make fclean
	make all
