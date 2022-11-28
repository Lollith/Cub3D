# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 11:05:42 by agouet            #+#    #+#              #
#    Updated: 2022/11/28 16:31:17 by esmirnov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3D

S_MLX			= minilibx-linux

MLX				= $(S_MLX)/libmlx_Linux.a

#LIBFT			= libft/libft.a

RM				= rm -rf

MKDIR			= mkdir -p
# ---------------------------------------------------------------------------- #
# Mandatory source files
# ---------------------------------------------------------------------------- #
WINDOW_SRCS		:= hook.c window.c
	
PARSING_SRCS	:= checks.c init.c parse.c parse_get_img.c parse_get_color.c\
					parse_get_map.c parse_tools.c utils_1.c utils_2.c free.c\
					map_square.c\
					

RENDER_SRCS		:= draw.c move.c img.c

GNL_SRCS		:= get_next_line.c\
					get_next_line_utils.c 

MAIN_SRCS		:= main.c

SRCS_PATH		:= sources/
SRCS			:= $(MAIN_SRCS)
SRCS			+= $(addprefix window/, $(WINDOW_SRCS))
SRCS			+= $(addprefix render/, $(RENDER_SRCS))
SRCS			+= $(addprefix parsing/,$(PARSING_SRCS))
SRCS			+= $(addprefix gnl/,$(GNL_SRCS))
SRCS			:= $(addprefix $(SRCS_PATH), $(SRCS))
# ---------------------------------------------------------------------------- #
# Object files & Dependencies
# ---------------------------------------------------------------------------- #
OBJS_PATH		:= objects/
OBJS			:= $(SRCS:${SRCS_PATH}%.c=${OBJS_PATH}%.o)
DEPS			:= $(SRCS:${SRCS_PATH}%.c=${OBJS_PATH}%.d)
# ---------------------------------------------------------------------------- #
# Compiler and flags
# ---------------------------------------------------------------------------- #
CC				= cc

CFLAGS			= -Wall -Wextra -Werror -MMD -g3 -O3 #g at place of -g 

LDFLAGS			= -lmlx_Linux -lXext -lX11 -lm -lz

LIB				= -L ./minilibx-linux -L /usr/lib

INC				= -I ./includes  -I /usr/include  -I minilibx-linux
# ---------------------------------------------------------------------------- #
# Rules
# ---------------------------------------------------------------------------- #
all:			$(NAME)

$(NAME):		$(OBJS) $(MLX)# $(LIBFT)#
				$(CC) $(CFLAGS) -o $(NAME) $(MLX) $(OBJS) $(LIB) $(LDFLAGS)

$(MLX):
				make -C $(S_MLX)

#(LIBFT):
#				@make -C libft/
#-p if directory exists do not create new(no warning etc)
$(OBJS_PATH)%.o:	$(SRCS_PATH)%.c
				$(MKDIR) ${dir $@}
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

# ---------------------------------------------------------------------------- #
# 
# ---------------------------------------------------------------------------- #
# ---------------------------------------------------------------------------- #
# Colors
# ---------------------------------------------------------------------------- #