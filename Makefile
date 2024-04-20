CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS_LIBFT = libft/ft_strncmp.c libft/ft_strlen.c libft/ft_split.c libft/ft_putstr_fd.c libft/ft_strjoin.c libft/ft_strdup.c libft/ft_substr.c 
SRCS = Mandatory/main.c Mandatory/utils.c Mandatory/pipex.c 
SRCS_BONUS = Bonus/main.c Bonus/utils.c Bonus/pipex_bonus.c Bonus/utils2.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OBJS_LIBFT = $(SRCS_LIBFT:.c=.o)
NAME = pipex
NAME_BONUS = pipex_bonus
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)
bonus: $(NAME_BONUS)


$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): $(SRCS_LIBFT)
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)

fclean: clean clean_bonus
	rm -f $(NAME) $(NAME_BONUS)
	make -C $(LIBFT_DIR) fclean

re:	fclean all
clean_bonus:
	rm -f $(OBJS_BONUS)
