# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agouet <agouet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 11:05:42 by agouet            #+#    #+#              #
#    Updated: 2022/11/14 14:48:11 by agouet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

S_MLX		= minilibx-linux

SRCS		= 	$(addprefix gnl/, get_next_line.c get_next_line_utils.c)\
				$(addprefix sources/, main.c) 

MLX			= $(S_MLX)/libmlx_Linux.a

OBJS		= $(SRCS:.c=.o)

DEPS		= $(SRCS:.c=.d)

CC			= cc

CFLAGS		= -MMD -Wall -Wextra -Werror -g -O3

LDFLAGS		= -lmlx_Linux -lXext -lX11 -lm  -lz

LIB			= -L ./minilibx-linux -L /usr/lib

INC			= -I ./includes  -I /usr/include  -I minilibx-linux


all:		$(NAME)

$(MLX):
			make -C $(S_MLX) 
			
$(NAME):	$(OBJS) $(MLX)
			$(CC) $(CFLAGS) -o $(NAME) $(MLX) $(OBJS) $(LIB) $(LDFLAGS)

%.o			:%.c
			$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:	
			make -C $(S_MLX) clean
			rm -f $(OBJS) $(DEPS)

fclean:		clean
			rm -f $(NAME)

re:			fclean
			make -C .

.PHONY:		all re clean fclean 

-include $(DEPS)