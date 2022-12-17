# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 20:56:58 by juwkim            #+#    #+#              #
#    Updated: 2022/12/18 02:33:43 by juwkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define the compiler and flags
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -MMD -O3
LDFLAGS 		=	-framework OpenGL -framework Appkit -l z
LIBMLX			=	libmlx.dylib
LDLIBS 			=	lib/ft_printf.a lib/get_next_line.a lib/libft.a $(LIBMLX)

# Define the directories
SRC_DIR			=	sources
BUILD_DIR		=	build

CORE_DIR 		=	core
MONSTER_DIR 	=	monster
OTHER_DIR		=	other
PARSING_DIR 	=	parsing
PLAYER_DIR		=	player
TOOLS_DIR		=	tools

# Define the source files
SRCS_CORE		=	$(addprefix $(CORE_DIR)/, main.c init.c draw.c error.c hook.c sprite.c)
SRCS_MONSTER	=	$(addprefix $(MONSTER_DIR)/, monster.c monster_distance.c monster_position.c monster_interaction.c monster_movement.c monster_sprite1.c)
SRCS_OTHER		=	$(addprefix $(OTHER_DIR)/, wall.c background.c item.c gate.c)
SRCS_PARSING	=	$(addprefix $(PARSING_DIR)/, parsing1.c parsing2.c)
SRCS_PLAYER		=	$(addprefix $(PLAYER_DIR)/, player.c player_position.c player_action.c player_distance.c player_mouvement.c player_gravity.c player_draw.c player_count_movement.c player_sprite1.c player_sprite2.c)
SRCS_TOOLS		=	$(addprefix $(TOOLS_DIR)/, fps.c hud.c)

SRCS_TOTAL		=	$(SRCS_CORE) $(SRCS_MONSTER) $(SRCS_OTHER) $(SRCS_PARSING) $(SRCS_PLAYER) $(SRCS_TOOLS)

SRCS			=	$(addprefix $(SRC_DIR)/, $(SRCS_TOTAL))
OBJS			=	$(patsubst %.c, $(BUILD_DIR)/%.o, $(SRCS_TOTAL))
DEPS			=	$(patsubst %.c, $(BUILD_DIR)/%.d, $(SRCS_TOTAL))

-include $(DEPS)

# Define the target
NAME			=	so_long

all bonus: $(NAME)

# Define the target and dependencies
$(NAME) : $(LDLIBS) $(OBJS)
	@$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
	@echo "\n${GREEN}> Compilation of the so_long is success 🎉${END}"

$(BUILD_DIR)/$(CORE_DIR)/%.o: $(SRC_DIR)/$(CORE_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $^ -o $@
	@echo -n .

$(BUILD_DIR)/$(MONSTER_DIR)/%.o: $(SRC_DIR)/$(MONSTER_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $^ -o $@
	@echo -n .

$(BUILD_DIR)/$(OTHER_DIR)/%.o: $(SRC_DIR)/$(OTHER_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $^ -o $@
	@echo -n .

$(BUILD_DIR)/$(PARSING_DIR)/%.o: $(SRC_DIR)/$(PARSING_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $^ -o $@
	@echo -n .

$(BUILD_DIR)/$(PLAYER_DIR)/%.o: $(SRC_DIR)/$(PLAYER_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $^ -o $@
	@echo -n .

$(BUILD_DIR)/$(TOOLS_DIR)/%.o: $(SRC_DIR)/$(TOOLS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $^ -o $@
	@echo -n .

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