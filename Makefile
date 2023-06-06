# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 19:47:17 by jeelee            #+#    #+#              #
#    Updated: 2023/06/06 20:15:35 by jeelee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	miniRT

CC			=	CC
CFLAGS		=	-Wall -Wextra -Werror

LIBDIR		=	./libft
LIBFT		=	$(LIBDIR)/libft.a

MLXDIR		=	./mlx
MLX			=	$(MLXDIR)/libmlx.a
LDFLAGS		=	-L./mlx/ -lmlx -framework OpenGL -framework AppKit

SRC			=	main.c

OBJ			=	$(SRC:.c=.o)

$(NAME)		:	$(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(LIBFT) $(MLX) $(LDFLAGS) $(OBJ) -o $@

%.o			:	%.c
	$(CC) $(CFLAGS) -c $?

$(LIBFT)	:
	make -C $(LIBDIR)

$(MLX)		:
	make -C $(MLXDIR)

all			:	$(NAME)

clean		:
	@make -C $(LIBDIR) clean
	@make -C $(MLXDIR) clean
	@rm -f $(OBJ)

fclean		:	clean
	@rm -f $(NAME) $(LIBFT) $(MLX)

re			:
	@make fclean
	@make all

.PHONY		:	all clean fclean re