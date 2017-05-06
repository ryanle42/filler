# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle <rle@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/12 16:29:53 by rle               #+#    #+#              #
#    Updated: 2017/05/06 12:49:20 by rle              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

OBJS = $(addprefix ./srcs/, \
 			main.o \
 			init.o \
 			get_map.o \
 			get_piece.o \
 			solver.o \
 			distance.o \
 			get_shift.o \
 			heatmap.o \
 		)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I ./includes -I ./libft/includes

LIB = libft

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(CFLAGS) $(LIB)/libft.a $(OBJS) $(INCLUDES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(LIB): force
	$(MAKE) -C libft

force: 
	@true

clean:
	rm $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
