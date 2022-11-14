# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agouet <agouet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 11:05:42 by agouet            #+#    #+#              #
#    Updated: 2022/11/14 11:48:14 by agouet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Cub3D

MLX			= mlx_linux/libmlx_Linux.a

SRCS		= $(addprefix sources/, \
				main.c)
				
OBJS		= $(SRCS:.c=.o)

DEPS		= $(SRCS:.c=.d)

CC			= cc

CFLAGS		= -MMD -Wall -Wextra -Werror -g -O3

LDFLAGS		= -lmlx_Linux -lXext -lX11 -lm  -lz

LIB			= -L ./mlx_linux -L /usr/lib

INC			= -I ./includes  -I /usr/include  -I mlx_linux


all:		$(NAME) 

$(NAME):	$(OBJS) $(MLX)
			make -C ./mlx_linux
			$(CC) $(CFLAGS) -o $(NAME) $(MLX) $(OBJS) $(LIB) $(LDFLAGS)

%.o			:%.c
			$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:	
			make clean -C mlx_linux
			rm -f $(OBJS) $(DEPS)

fclean:		clean
			make -C mlx_linux clean
			rm -f $(NAME)

re:			fclean
			make

.PHONY:		all re clean fclean 

-include $(DEPS)