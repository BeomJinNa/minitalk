#parameters====================================================================

CC		= cc
AR		= ar
ARFLAGS	= crs
CFLAGS	= -Wall -Wextra -Werror

NAME	= test
B_NAME	= test_bonus
INCLUDE	= includes/



#libraries=====================================================================

LIBS	= libft
B_LIBS	= libft_bonus
ARCH	= ft
B_ARCH	= ft_bonus

LIBFT	= libft/libft.a
LIBFT_B	= libft_bonus/libft_bonus.a



#sources=======================================================================

SRCS	= main.c

B_SRCS	=

OBJS	= $(SRCS:.c=.o)
B_OBJS	= $(B_SRCS:.c=.o)




#rules=========================================================================

.PHONY: all
all :
	make $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(foreach lib, $(LIBS), -L$(lib)) $(foreach arch, $(ARCH), -l$(arch))

$(LIBFT) :
	make -C libft



.PHONY: bonus
bonus :
	make $(B_NAME)

$(B_NAME) : $(LIBFT_B) $(B_OBJS)
	$(CC) -o $(B_NAME) $(B_OBJS) $(foreach lib, $(B_LIBS), -L$(lib)) $(foreach arch, $(B_ARCH), -l$(arch))

$(LIBFT_B) :
	make -C libft_bonus





#const options=================================================================

%.o : %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

.PHONY: clean
clean :
	$(foreach lib, $(LIBS), make fclean -C $(lib);)
	$(foreach lib, $(B_LIBS), make fclean -C $(lib);)
	rm -f $(OBJS) $(B_OBJS)

.PHONY: fclean
fclean :
	make clean
	rm -f $(NAME)
	rm -f $(B_NAME)

.PHONY: re
re :
	make fclean
	make all
