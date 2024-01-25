# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 00:17:25 by sagemura          #+#    #+#              #
#    Updated: 2024/01/25 15:06:29 by sagemura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HELPERFUNCNAME = helperfunc.a

SRCS =   main.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror 
HELPERFUNCDIR = ./helperfunc
LIBFTDIR = ./helperfunc/libft
SORTFUNCDIR = ./helperfunc/sortfunc
SLDIR = ./seach_memory_leaks

LIBFT = $(LIBFTDIR)/libft.a
SORTFUNCNAME = $(SORTFUNCDIR)/sortfunc.a

all: $(NAME)

makehelperfunc:
	make -C $(HELPERFUNCDIR)
	
$(NAME):makehelperfunc $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(HELPERFUNCDIR)/$(HELPERFUNCNAME) $(LIBFT) $(SORTFUNCNAME) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS)
	cd $(HELPERFUNCDIR) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(HELPERFUNCDIR) && make fclean

re: fclean all

.PHONY: all clean fclean re bonus