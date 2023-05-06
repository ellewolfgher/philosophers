# NAME = philo
# SRCS = main.c init.c status.c feast.c utils.c
# CC = gcc
# FLAGS = -Wall -Wextra -Werror -pthread -g
# DATARACE = -fsanitize=thread -g

# all: $(NAME)

# $(NAME): $(SRCS)
# 	@$(CC) $(FLAGS) $(SRCS) -o $(NAME) 

# datarace:
# 	@$(CC) $(DATARACE) $(SRCS) -o $(NAME)

# clean:
# 	@rm -rf *.o

# fclean: clean
# 	@rm -rf $(NAME)

# re: fclean all

NAME	= philo
CC		= cc
FLAGS	= -Wall -Wextra -Werror -g
PFLAG	= -lm -pthread
DATARACE = -fsanitize=thread -g

SRC_PATH = srcs/
OBJ_PATH = objs/

SRC		= main.c init.c feast.c status.c utils.c
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./include/

all: $(OBJ_PATH) $(NAME) 

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(FLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(PFLAG)

datarace:
	$(CC) $(DATARACE) $(SRCS) -o $(NAME) $(PFLAG)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all datarace clean fclean re