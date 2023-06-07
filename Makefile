NAME = pipex

CC = cc
CFLAGS = -Werror -Wall -Wextra

MAKE = make
MFLAGS = -C

RM = rm
RMFLAGS = -rf

LIBFT_DIR = ./libft
LIBFT_SRCS = \
./libft/ft_split.c \
./libft/ft_strncmp.c \
./libft/ft_substr.c \
./libft/ft_strlen.c

MANDATORY_SRCS = \
pipex.c \
pipex_utils.c
MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(MANDATORY_OBJS) $(LIBFT_SRCS)
	$(MAKE) $(MFLAGS) $(LIBFT_DIR) all
	$(CC) $(CFLAGS) -o $@ $(MANDATORY_OBJS) -L./libft -lft

$(MANDATORY_OBJS) : $(MANDATORY_SRCS) 
	$(CC) $(CFLAGS) -c $^

clean :
	$(MAKE) $(MFLAGS) $(LIBFT_DIR) clean
	$(RM) $(RMFLAGS) $(MANDATORY_OBJS)

fclean : clean
	$(MAKE) $(MFLAGS) $(LIBFT_DIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re