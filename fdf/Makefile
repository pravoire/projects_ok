# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 00:33:51 by pravoire          #+#    #+#              #
#    Updated: 2016/10/10 18:52:34 by pravoire         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf 
CFLAGS = -Wall -Werror -Wextra
SRCS = fdf.c \
	   parser.c \
	   hooks.c \
	   error.c \
	   graph.c \
	   transform.c \
	   color.c \
	   bresenham.c \
	   bre_quad_1.c \
	   bre_quad_2.c \
	   bre_quad_3.c \
	   bre_quad_4.c
OBJS = $(SRCS:.c=.o)
LIBS = -lmlx -framework OpenGL -framework AppKit -L./libft/ -lft
LIBFT = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft/
	gcc $(CFLAGS) -o $@ $(OBJS) $(LIBS)

%.o: %.c
	gcc $(CFLAGS) $< -o $@ -c

clean:
	rm -rf $(OBJS)
	make clean -C ./libft/

fclean: clean
	rm -rf $(NAME)
	rm -rf ./libft/libft.a

re: fclean all
