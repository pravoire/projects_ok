# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pravoire <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/09 18:19:41 by pravoire          #+#    #+#              #
#    Updated: 2017/05/10 12:26:56 by pravoire         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
# Compilation tools
#

CC =			gcc

CC_FLAGS =		-Wall -Wextra -Werror

#
# Target
#

NAME =			wolf3d

#
# Headers decalarations
#

INC_DIR =		includes

DEP =			$(INC_DIR)/wolf3d.h

#
# Sources declarations
#

SRC_DIR =		srcs
SRC =			$(SRC_DIR)/main.c\
				$(SRC_DIR)/draw.c\
				$(SRC_DIR)/error.c\
				$(SRC_DIR)/get_next_line.c\
				$(SRC_DIR)/init.c\
				$(SRC_DIR)/key.c\
				$(SRC_DIR)/loop_hook.c\
				$(SRC_DIR)/move.c\
				$(SRC_DIR)/ray.c\
				$(SRC_DIR)/read.c

OBJ =			$(SRC:.c=.o)

#
# Library declarations
#

LIB_DIR =		lib

LFT_DIR =		$(LIB_DIR)/ft
LFT =			libft.a
LFT_C =			-lft

MLX_DIR =		$(LIB_DIR)/minilibx_macos
MLX =			libmlxt.a
MLX_C =			-lmlxt

FRM_WRK =		-framework OpenGL -framework Appkit

#
# Rules
#

all :			$(NAME)

$(NAME) : $(LFT) $(MLX) $(OBJ)
	$(CC) $(CC_FLAGS) -o $@ $^ -I $(INC_DIR) -I $(LFT_DIR)/$(INC_DIR) -I $(MLX_DIR) $(FRM_WRK)

$(LFT) :
	@echo 'Compiling libft...'
	@make -C $(LFT_DIR)
	@mv $(LFT_DIR)/$(LFT) .
	@echo 'Compilation ended successfully.'

$(MLX) :
	@echo 'Compiling minilibx...'
	@make -C $(MLX_DIR)
	@mv $(MLX_DIR)/$(MLX) .
	@echo 'Compilation ended successfully.'

%.o : %.c $(DEP)
	@$(CC) $((CC_FLAGS) -o $@ -I $(INC_DIR) -I $(LFT_DIR)/$(INC_DIR) -I $(MLX_DIR)/$(INC_DIR) -c $<

clean :
	@echo 'Cleaning objects files...'
	@rm -rf $(OBJ)
	@make clean -C $(LFT_DIR)
	@make clean -C $(MLX_DIR)
	@echo 'Deletion complete.'

fclean : clean
	@echo 'Cleaning libs and exe...'
	@rm -rf $(NAME)
	@rm -rf $(LFT) $(MLX)
	@echo 'Deletion complete.'

re : fclean all
