# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 15:23:07 by aoubhoum          #+#    #+#              #
#    Updated: 2023/04/30 13:27:36 by aoubhoum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_B = checker

SOURCES = push_swap.c parsing_funcs.c check.c ft_lst.c\
	rules.c rules1.c rules3.c sorting.c\
	utils.c  utils2.c utils3.c norm_handel.c\

SOURCES_B = get_next_line.c get_next_line_utils.c reules_bonus.c rules1_bonus.c\
	rules3_bonus.c checker.c parsing_funcs.c ft_lst.c check.c\
	read_line.c\

OBJECTS_B = $(SOURCES_B:.c=.o)
OBJECTS = $(SOURCES:.c=.o)
LIBFT = libft/libft.a
LIBFT_DIR = libft/
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
bonus: $(NAME_B)

$(NAME): $(OBJECTS) $(LIBFT) push_swap.h 
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

$(NAME_B): $(OBJECTS_B) $(LIBFT) push_swap.h 
	$(CC) $(CFLAGS) $(OBJECTS_B) $(LIBFT) -o $(NAME_B)

%.o: %.c push_swap.h
	$(CC) -c $(CFLAGS)  $<

$(LIBFT) : 
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJECTS)

clean_b:
	rm -f $(OBJECTS_B)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

fclean_b: clean_b
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(NAME_B)

re: fclean all

re_bonus: fclean_b bonus
