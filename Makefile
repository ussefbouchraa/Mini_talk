NAME = server
CLIENT = client

CC = cc -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs 
FILES =  server.c
C_FILES = client.c

OBJS = $(FILES:.c=.o)
C_OBJ = $(C_FILES:.c=.o)

all : $(NAME) $(CLIENT)

$(NAME) : $(OBJS)
	$(CC) $^ -o $@

$(CLIENT): $(C_OBJ)
	$(CC) $^ -o $@

%.o : %.c minitalk.h
	$(CC) -c $< -o $@

clean : 
	$(RM) $(OBJS) $(C_OBJ)

fclean : clean
	$(RM) $(NAME) $(CLIENT)

re : fclean all
