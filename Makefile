# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kojwatan <kojwatan@student.42tokyo.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 13:58:57 by kojwatan          #+#    #+#              #
#    Updated: 2024/01/24 14:25:36 by kojwatan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wextra -Werror -Wall
SRCS = ./srcs/main.c \
	./srcs/stack_utils.c \
	./srcs/terminate.c ./srcs/control_stack.c \
	./srcs/swap.c ./srcs/push.c \
	./srcs/rotate.c ./srcs/reverse_rotate.c \
	./srcs/sort.c ./srcs/control_a.c \
	./srcs/control_b.c ./srcs/stack_pivot.c \
	./srcs/check.c ./srcs/move_stack2stack.c \
	./srcs/quick_sort.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C ./libft clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
