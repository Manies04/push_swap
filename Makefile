# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 15:59:56 by tiade-al          #+#    #+#              #
#    Updated: 2024/10/22 23:01:06 by tiade-al         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = srcs/error_management.c \
	srcs/finders.c \
	srcs/helpers.c \
	srcs/init_a_nodes.c \
	srcs/main.c \
	srcs/sort.c \
	srcs/sorting_func.c \
	srcs/stack_sorting.c \
	srcs/operations/push.c \
	srcs/operations/reverse_rotate.c \
	srcs/operations/rotate.c \
	srcs/operations/swap.c


CC = @cc

CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = ./Libft
LIBFT = $(LIBFT_PATH)/libft.a

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@echo " [ .. ] | Compiling.."
	@make -s -C $(LIBFT_PATH)
	@echo " [ OK ] | Ready!"

clean:
	@rm -f $(OBJS)
	@echo "object files removed."
	
fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "all files created were removed."

re: fclean all

.PHONY:	all clean fclean re