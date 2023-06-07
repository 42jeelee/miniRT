# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 19:47:17 by jeelee            #+#    #+#              #
#    Updated: 2023/06/07 18:01:55 by ahkiler          ###   ########.fr        #
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

SRCDIR		=	src
SRC			=	main.c \
				$(SRCDIR)/img/init_img.c \
				$(SRCDIR)/img/print_img.c \
				$(SRCDIR)/hook/hook.c \


OBJ			=	$(SRC:.c=.o)

$(NAME)		:	$(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(LIBFT) $(MLX) $(LDFLAGS) $(OBJ) -o $@

%.o			:	%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT)	:
	make -C $(LIBDIR)

$(MLX)		:
	make -C $(MLXDIR)

all			:
	@$(MAKE) -j6 $(NAME)

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