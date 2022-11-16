# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agouet <agouet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 11:05:42 by agouet            #+#    #+#              #
#    Updated: 2022/11/15 18:21:55 by esmirnov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3D

CC				= cc

S_MLX			= minilibx-linux

MLX				= $(S_MLX)/libmlx_Linux.a

WINDOW_SRCS		:= hook.c\
					window.c
	
PARSING_SRCS	:= checks.c\
					init.c\
					map_square.c\
					utils.c

GNL_SRCS		:= get_next_line.c\
					get_next_line_utils.c 

MAIN_SRCS		:= main.c

SRCS			:= $(MAIN_SRCS)
SRCS			+= $(addprefix window/, $(WINDOW_SRCS))
SRCS			+= $(addprefix parsing/,$(PARSING_SRCS))

SRCS			+= $(addprefix gnl/,$(GNL_SRCS))

OBJS			:= $(SRCS:.c=.o)
DEPS			:= $(SRCS:.c=.d)

SRCS_PATH		:= sources/
OBJS_PATH		:= objects/
SRCS			:= $(addprefix $(SRCS_PATH), $(SRCS))
OBJS			:= $(addprefix $(OBJS_PATH), $(OBJS))
DEPS			:= $(addprefix $(OBJS_PATH), $(DEPS))

#SRCS			= 	$(addprefix gnl/, get_next_line.c get_next_line_utils.c)\
				$(addprefix sources/, main.c) \
				$(addprefix sources/window/, window.c hook.c)



CFLAGS			= -Wall -Wextra -Werror -MMD -g3 -O3 #g at place of -g 

LDFLAGS			= -lmlx_Linux -lXext -lX11 -lm  -lz

LIB				= -L ./minilibx-linux -L /usr/lib

INC				= -I ./includes  -I /usr/include  -I minilibx-linux

RM				= rm -rf

#LIBFT			= libft/libft.a

all:			objects_dir $(NAME)

objects_dir:
				mkdir -p objects
				mkdir -p objects/window
				mkdir -p objects/parsing
				mkdir -p objects/gnl

$(NAME):		$(OBJS) $(MLX)# $(LIBFT)#
				$(CC) $(CFLAGS) -o $(NAME) $(MLX) $(OBJS) $(LIB) $(LDFLAGS)

$(MLX):
				make -C $(S_MLX)

#(LIBFT):
#				@make -C libft/

#-p if directory exists(is no warning etc)
$(OBJS_PATH)%.o:	$(SRCS_PATH)%.c
				$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:	
				make -C $(S_MLX) clean
				$(RM) $(OBJS) $(DEPS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean
				make -C .

-include $(DEPS)

.PHONY:			all re clean fclean