# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 20:56:58 by juwkim            #+#    #+#              #
#    Updated: 2022/12/28 13:56:21 by juwkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define the compiler and flags
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -MMD -O3
LDFLAGS 		=	-framework OpenGL -framework Appkit
LIBMLX			=	libmlx.dylib
LDLIBS 			=	lib/ft_printf.a lib/get_next_line.a lib/libft.a $(LIBMLX)

# Define the directories
SRC_DIR			=	sources
INC_DIR			=	includes
BUILD_DIR		=	build

CORE_DIR 		=	core
MONSTER_DIR 	=	monster
PLAYER_DIR		=	player
TOOLS_DIR		=	tools

# Define the source files
SRCS_MAIN		=	main.c
SRCS_CORE		=	$(addprefix $(CORE_DIR)/, collectable.c draw.c gate.c hook.c image.c init.c map.c)
SRCS_MONSTER	=	$(addprefix $(MONSTER_DIR)/, monster.c monster_distance.c monster_position.c monster_interaction.c monster_movement.c monster_sprite.c)
SRCS_PLAYER		=	$(addprefix $(PLAYER_DIR)/, player_distance.c player_image.c player_image2.c player_move.c player.c)
SRCS_TOOLS		=	$(addprefix $(TOOLS_DIR)/, error.c point.c time_stamp.c)

SRCS_MONSTER	=
SRCS_TOTAL		=	$(SRCS_MAIN) $(SRCS_CORE) $(SRCS_MONSTER) $(SRCS_PLAYER) $(SRCS_TOOLS)

SRCS			=	$(addprefix $(SRC_DIR)/, $(SRCS_TOTAL))
OBJS			=	$(patsubst %.c, $(BUILD_DIR)/%.o, $(SRCS_TOTAL))
DEPS			=	$(patsubst %.c, $(BUILD_DIR)/%.d, $(SRCS_TOTAL))

-include $(DEPS)
# Define the target
NAME			=	so_long

all: $(NAME)
bonus: all
# Define the target and dependencies
$(NAME) : $(LDLIBS) $(OBJS)
	@$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
	@echo "${GREEN}> Compilation of the so_long is success 🎉${END}"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(BUILD_DIR)/$(CORE_DIR)/%.o: $(SRC_DIR)/$(CORE_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(BUILD_DIR)/$(MONSTER_DIR)/%.o: $(SRC_DIR)/$(MONSTER_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(BUILD_DIR)/$(OTHER_DIR)/%.o: $(SRC_DIR)/$(OTHER_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(BUILD_DIR)/$(PARSING_DIR)/%.o: $(SRC_DIR)/$(PARSING_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(BUILD_DIR)/$(PLAYER_DIR)/%.o: $(SRC_DIR)/$(PLAYER_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(BUILD_DIR)/$(TOOLS_DIR)/%.o: $(SRC_DIR)/$(TOOLS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(DEPS)
	@rm -rf $(BUILD_DIR)
	@make clean -C ./lib
	@echo "${YELLOW}> All objects files of the so_long have been deleted ❌${END}"

fclean:
	@$(RM) $(OBJS) $(DEPS) $(LIBS) $(NAME) $(LIBMLX)
	@rm -rf $(BUILD_DIR)
	@make fclean -C ./lib
	@echo "${YELLOW}> Cleaning of the so_long has been done ❌${END}"

re: fclean
	@make all

$(LDLIBS) :
	@make -C ./lib

.PHONY:	all bonus clean fclean re

# minimal color codes
END				=	$'\x1b[0m
BOLD			=	$'\x1b[1m
UNDER			=	$'\x1b[4m
REV				=	$'\x1b[7m
GREY			=	$'\x1b[30m
RED				=	$'\x1b[31m
GREEN			=	$'\x1b[32m
YELLOW			=	$'\x1b[33m
BLUE			=	$'\x1b[34m
PURPLE			=	$'\x1b[35m
CYAN			=	$'\x1b[36m
WHITE			=	$'\x1b[37m