# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lollith <lollith@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 11:05:42 by agouet            #+#    #+#              #
#    Updated: 2022/11/18 14:40:08 by esmirnov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3D

CC				= cc

S_MLX			= minilibx-linux

MLX				= $(S_MLX)/libmlx_Linux.a

WINDOW_SRCS		:= hook.c window.c
	
PARSING_SRCS	:= checks.c init.c parse.c utils.c map_square.c

RENDER_SRCS		:= draw.c

GNL_SRCS		:= get_next_line.c\
					get_next_line_utils.c 

MAIN_SRCS		:= main.c

SRCS			:= $(MAIN_SRCS)
SRCS			+= $(addprefix window/, $(WINDOW_SRCS))
SRCS			+= $(addprefix render/, $(RENDER_SRCS))
SRCS			+= $(addprefix parsing/,$(PARSING_SRCS))
SRCS			+= $(addprefix gnl/,$(GNL_SRCS))

OBJS			:= $(SRCS:.c=.o)
DEPS			:= $(SRCS:.c=.d)

SRCS_PATH		:= sources/
OBJS_PATH		:= objects/
SRCS			:= $(addprefix $(SRCS_PATH), $(SRCS))
OBJS			:= $(addprefix $(OBJS_PATH), $(OBJS))
DEPS			:= $(addprefix $(OBJS_PATH), $(DEPS))


CFLAGS			= -Wall -Wextra -Werror -MMD -g3 -O3 #g at place of -g 

LDFLAGS			= -lmlx_Linux -lXext -lX11 -lm -lz

LIB				= -L ./minilibx-linux -L /usr/lib

INC				= -I ./includes  -I /usr/include  -I minilibx-linux

RM				= rm -rf

MKDIR			= mkdir -p

#LIBFT			= libft/libft.a


all:			$(NAME)

$(NAME):		$(OBJS) $(MLX)# $(LIBFT)#
				$(CC) $(CFLAGS) -o $(NAME) $(MLX) $(OBJS) $(LIB) $(LDFLAGS)

$(MLX):
				make -C $(S_MLX)

#(LIBFT):
#				@make -C libft/

objects_dir:
				$(MKDIR) objects
				$(MKDIR) objects/window
				$(MKDIR) objects/parsing
				$(MKDIR) objects/gnl

#-p if directory exists do not create new(no warning etc)
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

# ---------------------------------------------------------------------------- #
# 
# ---------------------------------------------------------------------------- #
# ---------------------------------------------------------------------------- #
# Mandatory source files
# ---------------------------------------------------------------------------- #
# ---------------------------------------------------------------------------- #
# Object files & Dependencies
# ---------------------------------------------------------------------------- #
# ---------------------------------------------------------------------------- #
# Directories and Paths
# ---------------------------------------------------------------------------- #
# ---------------------------------------------------------------------------- #
# Compiler and flags
# ---------------------------------------------------------------------------- #
# ---------------------------------------------------------------------------- #
# Rules
# ---------------------------------------------------------------------------- #
# ---------------------------------------------------------------------------- #
# Colors
# ---------------------------------------------------------------------------- #