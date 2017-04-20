# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle <rle@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/12 16:29:53 by rle               #+#    #+#              #
#    Updated: 2017/04/18 19:06:25 by rle              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

OBJS = $(addsuffix .o, main init get_map get_piece solver distance get_shift heatmap)

CC = gcc

INCLUDES = -I ./includes -I ./libft/includes

LIB = libft

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(LIB)/libft.a $(OBJS) $(INCLUDES) -o $(NAME)

%.o: %.c
	gcc -c $< $(INCLUDES)

$(LIB): force
	$(MAKE) -C libft

force: 
	@true

clean:
	rm $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
