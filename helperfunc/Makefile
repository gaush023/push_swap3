# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 00:17:25 by sagemura          #+#    #+#              #
#    Updated: 2024/01/22 14:26:44 by sagemura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = helperfunc.a
LIBFTNAME = libft.a
SORTFUNCNAME = sortfunc.a
SRCS =   free_split.c   free_stacks.c ft_check_argc.c \
ft_print_error.c is_sorted.c node.c node_2.c

OBJS = $(SRCS:.c=.o)

CC = cc

LIBFTDIR = ./libft
SORTFUNCDIR = ./sortfunc
CFLAGS = -Wall -Wextra -Werror -I$(SORTFUNCDIR) -I$(LIBFTDIR)

all: $(NAME)

$(NAME): makelibft makesortfunc $(OBJS)
		ar rcs $(NAME) $(OBJS)

makelibft:
	make -C $(LIBFTDIR)

makesortfunc:
	make -C $(SORTFUNCDIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@	

clean:
	rm -f $(OBJS)
	cd $(LIBFTDIR) && make clean
	cd $(SORTFUNCDIR) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBFTDIR) && make fclean
	cd $(SORTFUNCDIR) && make fclean

re: fclean all

.PHONY: all clean fclean re bonus