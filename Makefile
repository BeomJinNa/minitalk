#parameters====================================================================

CC		= cc
AR		= ar
ARFLAGS	= crs
CFLAGS	= -Wall -Wextra -Werror

SERVER	= server
CLIENT	= client
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

SB_SRCS = bonus/server_bonus.c

CB_SRCS = bonus/client_bonus.c

S_OBJS	= $(S_SRCS:.c=.o)
C_OBJS	= $(C_SRCS:.c=.o)
SB_OBJS	= $(SB_SRCS:.c=.o)
CB_OBJS	= $(CB_SRCS:.c=.o)




ifdef BONUS
	TARGET_C_OBJS = $(CB_OBJS)
	TARGET_S_OBJS = $(SB_OBJS)
	TARGET_LIB = $(LIBFT_B)
	TARGET_LIBS = $(B_LIBS)
	TARGET_ARCH = $(B_ARCH)
else
	TARGET_C_OBJS = $(C_OBJS)
	TARGET_S_OBJS = $(S_OBJS)
	TARGET_LIB = $(LIBFT)
	TARGET_LIBS = $(LIBS)
	TARGET_ARCH = $(ARCH)
endif

#rules=========================================================================

.PHONY: all
all :
	make $(SERVER)
	make $(CLIENT)

$(SERVER) : $(TARGET_LIB) $(TARGET_S_OBJS)
	$(CC) -o $@ $(TARGET_S_OBJS) $(foreach lib, $(TARGET_LIBS), -L$(lib)) $(foreach arch, $(TARGET_ARCH), -l$(arch))

$(CLIENT) : $(TARGET_LIB) $(TARGET_C_OBJS)
	$(CC) -o $@ $(TARGET_C_OBJS) $(foreach lib, $(TARGET_LIBS), -L$(lib)) $(foreach arch, $(TARGET_ARCH), -l$(arch))

$(LIBFT) :
	make -C libft

$(LIBFT_B) :
	make -C libft_bonus


.PHONY: bonus
bonus :
	make BONUS=0 $(SERVER)
	make BONUS=0 $(CLIENT)
#const options=================================================================

%.o : %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

.PHONY: clean
clean :
	$(foreach lib, $(LIBS), make fclean -C $(lib);)
	$(foreach lib, $(B_LIBS), make fclean -C $(lib);)
	rm -f $(S_OBJS) $(C_OBJS) $(SB_OBJS) $(CB_OBJS)

.PHONY: fclean
fclean :
	make clean
	rm -f $(SERVER)
	rm -f $(CLIENT)

.PHONY: re
re :
	make fclean
	make all
