CC		=	cc
AR		=	ar
ARFLAGS	=	crs
CFLAGS	=	-Wall -Wextra -Werror

NAME 	= 	libft_bonus.a

SRCS	=	ft_atoi_bonus.c \
			ft_bzero_bonus.c \
			ft_calloc_bonus.c \
			ft_isalnum_bonus.c \
			ft_isalpha_bonus.c \
			ft_isascii_bonus.c \
			ft_isdigit_bonus.c \
			ft_isprint_bonus.c \
			ft_itoa_bonus.c \
			ft_memchr_bonus.c \
			ft_memcmp_bonus.c \
			ft_memcpy_bonus.c \
			ft_memmove_bonus.c \
			ft_memset_bonus.c \
			ft_putchar_fd_bonus.c \
			ft_putendl_fd_bonus.c \
			ft_putnbr_fd_bonus.c \
			ft_putstr_fd_bonus.c \
			ft_split_bonus.c \
			ft_strchr_bonus.c \
			ft_strdup_bonus.c \
			ft_striteri_bonus.c \
			ft_strjoin_bonus.c \
			ft_strlcat_bonus.c \
			ft_strlcpy_bonus.c \
			ft_strlen_bonus.c \
			ft_strmapi_bonus.c \
			ft_strncmp_bonus.c \
			ft_strnstr_bonus.c \
			ft_strrchr_bonus.c \
			ft_strtrim_bonus.c \
			ft_substr_bonus.c \
			ft_tolower_bonus.c \
			ft_toupper_bonus.c \
		 	ft_lstadd_back_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstmap_bonus.c \
			ft_lstnew_bonus.c \
			ft_lstsize_bonus.c \
			ft_printf/ft_printf_bonus.c \
			ft_printf/putnbr_printf_bonus.c \
			ft_printf/print_char_bonus.c \
			ft_printf/print_dec_bonus.c \
			ft_printf/print_hex_bonus.c \
			ft_printf/print_int_bonus.c \
			ft_printf/print_ptr_bonus.c \
			ft_printf/print_str_bonus.c \
			ft_printf/print_uint_bonus.c \
			ft_printf/printf_utils_bonus.c \
			ft_printf/printf_utils2_bonus.c \
			ft_printf/printf_utils3_bonus.c \
			ft_printf/putaddress_bonus.c \
			ft_printf/puthex_bonus.c \
			ft_printf/putuint_bonus.c \
			get_next_line/get_next_line_bonus.c \
			get_next_line/get_next_line_utils_bonus.c

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
