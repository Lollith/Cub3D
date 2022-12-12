# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 11:05:42 by agouet            #+#    #+#              #
#    Updated: 2022/12/12 13:19:36 by esmirnov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3D

BONUS			= cub3D_bonus

S_MLX			= minilibx-linux

MLX				= $(S_MLX)/libmlx_Linux.a

RM				= rm -rf

MKDIR			= mkdir -p

# ---------------------------------------------------------------------------- #
# Mandatory source files
# ---------------------------------------------------------------------------- #

IO_SRCS			:= hook.c window.c move.c

PARSING_SRCS	:= init.c init_render.c init_struct.c parse.c\
					parse_get_tex_img.c parse_check_scan_map.c\
					parse_get_tex_color.c parse_get_map.c parse_check_map.c\
					msg_error.c utils_1.c utils_2.c free.c\
					
RENDER_SRCS		:= img_px.c img_tex.c raycasting.c dda.c draw.c

MANDATORY_SRCS  := draw_mandatory.c hook_mandatory.c

BONUS_SRCS		:= draw_bonus.c hook_bonus.c

GNL_SRCS		:= get_next_line.c\
					get_next_line_utils.c 

MAIN_SRCS		:= main.c

SRCS_PATH		:= sources/
SRCS			:= $(MAIN_SRCS)
SRCS			+= $(addprefix input_output/, $(IO_SRCS))
SRCS			+= $(addprefix mandatory/, $(MANDATORY_SRCS))
SRCS			+= $(addprefix render/, $(RENDER_SRCS)) 
SRCS			+= $(addprefix parsing/,$(PARSING_SRCS))
SRCS			+= $(addprefix gnl/,$(GNL_SRCS))
SRCS			:= $(addprefix $(SRCS_PATH), $(SRCS))

SRCS_BONUS		:= $(MAIN_SRCS)
SRCS_BONUS		+= $(addprefix input_output/, $(IO_SRCS))
SRCS_BONUS		+= $(addprefix bonus/, $(BONUS_SRCS))
SRCS_BONUS		+= $(addprefix render/, $(RENDER_SRCS))
SRCS_BONUS		+= $(addprefix parsing/,$(PARSING_SRCS))
SRCS_BONUS		+= $(addprefix gnl/,$(GNL_SRCS))
SRCS_BONUS		:= $(addprefix $(SRCS_PATH), $(SRCS_BONUS))

# ---------------------------------------------------------------------------- #
# Object files & Dependencies
# ---------------------------------------------------------------------------- #

OBJS_PATH		:= objects/
OBJS			:= $(SRCS:${SRCS_PATH}%.c=${OBJS_PATH}%.o)
DEPS			:= $(SRCS:${SRCS_PATH}%.c=${OBJS_PATH}%.d)
OBJS_BONUS		:= $(SRCS_BONUS:${SRCS_PATH}%.c=${OBJS_PATH}%.o)
DEPS_BONUS		:= $(SRCS_BONUS:${SRCS_PATH}%.c=${OBJS_PATH}%.d)

# ---------------------------------------------------------------------------- #
# Compiler and flags
# ---------------------------------------------------------------------------- #

CC				= cc

CFLAGS			= -Wall -Wextra -Werror -MMD -g3 -O3  #g at place of -g 

LDFLAGS			= -lmlx_Linux -lXext -lX11 -lm -lz

LIB				= -L ./minilibx-linux -L /usr/lib

INC				= -I ./includes  -I /usr/include  -I minilibx-linux

# ---------------------------------------------------------------------------- #
# Rules
# ---------------------------------------------------------------------------- #

all:			$(NAME)

bonus:			$(BONUS)

debug:			CFLAGS := -Werror -Wno-unused-variable 
debug:			$(NAME) # make debug

$(NAME):		$(OBJS) $(MLX)
				$(CC) $(CFLAGS) -o $(NAME) $(MLX) $(OBJS) $(LIB) $(LDFLAGS)

$(BONUS):		$(OBJS_BONUS) $(MLX)
				$(CC) $(CFLAGS) -o $(BONUS) $(MLX) $(OBJS_BONUS) $(LIB) $(LDFLAGS)

$(MLX):
				make -C $(S_MLX)

$(OBJS_PATH)%.o:	$(SRCS_PATH)%.c
				$(MKDIR) ${dir $@}
				$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:	
				make -C $(S_MLX) clean
				$(RM) $(OBJS) $(DEPS) $(OBJS_BONUS) $(DEPS_BONUS)

fclean:			clean
				$(RM) $(NAME)
				$(RM) $(BONUS)

re:				fclean
				make -C .

rebonus:		fclean bonus
				make bonus -C .

-include $(DEPS) $(DEPS_BONUS)

.PHONY:			all re clean fclean
