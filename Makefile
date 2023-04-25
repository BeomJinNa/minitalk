#parameters====================================================================

CC		= cc
AR		= ar
ARFLAGS	= crs
CFLAGS	= -Wall -Wextra -Werror

SERVER	= server
CLIENT	= client
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

S_SRCS	= srcs/server.c

C_SRCS	= srcs/client.c

S_OBJS	= $(S_SRCS:.c=.o)
C_OBJS	= $(C_SRCS:.c=.o)
B_OBJS	= $(B_SRCS:.c=.o)




#rules=========================================================================

.PHONY: all
all :
	make $(SERVER)
	make $(CLIENT)

$(SERVER) : $(LIBFT) $(S_OBJS)
	$(CC) -o $@ $(S_OBJS) $(foreach lib, $(LIBS), -L$(lib)) $(foreach arch, $(ARCH), -l$(arch))

$(CLIENT) : $(LIBFT) $(C_OBJS)
	$(CC) -o $@ $(C_OBJS) $(foreach lib, $(LIBS), -L$(lib)) $(foreach arch, $(ARCH), -l$(arch))

$(LIBFT) :
	make -C libft



#const options=================================================================

%.o : %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

.PHONY: clean
clean :
	$(foreach lib, $(LIBS), make fclean -C $(lib);)
	$(foreach lib, $(B_LIBS), make fclean -C $(lib);)
	rm -f $(S_OBJS) $(C_OBJS)

.PHONY: fclean
fclean :
	make clean
	rm -f $(SERVER)
	rm -f $(CLIENT)

.PHONY: re
re :
	make fclean
	make all
