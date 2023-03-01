# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 20:56:58 by juwkim            #+#    #+#              #
#    Updated: 2023/03/01 23:14:07 by juwkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
#   Define the compiler and flags                                              #
# ---------------------------------------------------------------------------- #

CC                  :=	cc
CFLAGS              :=	-Wall -Wextra -Werror -march=native -O2 -pipe
CPPFLAGS            =	-I include -I $(LIBFT)/include -I $(LIBMLX)
DEPFLAGS            =	-MMD -MP -MF $(DEP_DIR)/$*.d
LDFLAGS             =	-L $(LIBFT) -L $(LIBMLX)
LDLIBS              := -l ft -l mlx_Linux.a

ifdef DEBUG
	CFLAGS	+= -g -fsanitize=address,leak,undefined
endif

# ---------------------------------------------------------------------------- #
#   Define the libraries                                                       #
# ---------------------------------------------------------------------------- #

LIBFT               := libft
LIBMLX              := minilibx-linux

# ---------------------------------------------------------------------------- #
#   Define the directories                                                     #
# ---------------------------------------------------------------------------- #

SRC_DIR				:=	source
OBJ_DIR             :=	build/object
DEP_DIR             :=	build/dependency

CORE_DIR 			:=	core
MONSTER_DIR 		:=	monster
PLAYER_DIR			:=	player
UTILS_DIR			:=	utils

# ---------------------------------------------------------------------------- #
#   Define the source files                                                    #
# ---------------------------------------------------------------------------- #

SRCS                :=	$(SRC_DIR)/main.c $(wildcard $(SRC_DIR)/*/*.c)
OBJS                :=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
DEPS                :=	$(patsubst $(SRC_DIR)/%.c, $(DEP_DIR)/%.o, $(SRCS))

# ---------------------------------------------------------------------------- #
#   Define the variables for progress bar                                      #
# ---------------------------------------------------------------------------- #

TOTAL_FILES         :=	$(shell echo $(SRCS) | wc -w)
COMPILED_FILES      :=	0
STEP                :=	100

# ---------------------------------------------------------------------------- #
#   Define the name                                                            #
# ---------------------------------------------------------------------------- #

NAME                :=	so_long

# ---------------------------------------------------------------------------- #
#   Define the rules                                                           #
# ---------------------------------------------------------------------------- #

all:
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(LIBMLX)
	@$(MAKE) -j $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)
	@printf "\n$(MAGENTA)[SO_LONG] Linking Success\n$(DEF_COLOR)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | dir_guard
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c $< -o $@
	$(eval COMPILED_FILES = $(shell expr $(COMPILED_FILES) + 1))
	$(eval PROGRESS = $(shell expr $(COMPILED_FILES) "*" $(STEP) / $(TOTAL_FILES)))
	@printf "                                                                                                   \r"
	@printf "$(YELLOW)[SO_LONG] [%02d/%02d] ( %3d %%) Compiling $<\r$(DEF_COLOR)" $(COMPILED_FILES) $(TOTAL_FILES) $(PROGRESS)

dir_guard:
	@mkdir -p $(addprefix $(OBJ_DIR)/, $(CORE_DIR))
	@mkdir -p $(addprefix $(OBJ_DIR)/, $(MONSTER_DIR))
	@mkdir -p $(addprefix $(OBJ_DIR)/, $(PLAYER_DIR))
	@mkdir -p $(addprefix $(OBJ_DIR)/, $(UTILS_DIR))

	@mkdir -p $(addprefix $(DEP_DIR)/, $(CORE_DIR))
	@mkdir -p $(addprefix $(DEP_DIR)/, $(MONSTER_DIR))
	@mkdir -p $(addprefix $(DEP_DIR)/, $(PLAYER_DIR))
	@mkdir -p $(addprefix $(DEP_DIR)/, $(UTILS_DIR))

norm:
	@$(MAKE) -C $(LIBFT) norm
	@(norminette include source | grep Error) || (printf "$(GREEN)[SO_LONG] Norminette Success\n$(DEF_COLOR)")

clean:
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(LIBMLX) clean
	@$(RM) -r build
	@printf "$(BLUE)[SO_LONG] obj. dep. files$(DEF_COLOR)$(GREEN)	=> Cleaned!\n$(DEF_COLOR)"

fclean:
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBMLX) clean
	@$(RM) -r build $(NAME) $(LIBMLX)/libmlx_Linux.a
	@printf "$(BLUE)[SO_LONG] obj. dep. files$(DEF_COLOR)$(GREEN)  => Cleaned!\n$(DEF_COLOR)"
	@printf "$(CYAN)[SO_LONG] exec. files$(DEF_COLOR)$(GREEN)      => Cleaned!\n$(DEF_COLOR)"

re: fclean
	@$(MAKE) all
	@printf "$(GREEN)Cleaned and rebuilt everything for so_long!\n$(DEF_COLOR)"

debug:
	@$(MAKE) fclean
	@$(MAKE) -C $(LIBFT) DEBUG=1
	@$(MAKE) -j $(NAME) DEBUG=1

.PHONY: all clean fclean re dir_guard norm debug

# ---------------------------------------------------------------------------- #
#   Define the colors                                                          #
# ---------------------------------------------------------------------------- #

DEF_COLOR	=	\033[1;39m
GRAY		=	\033[1;90m
RED			=	\033[1;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[1;94m
MAGENTA		=	\033[1;95m
CYAN		=	\033[1;96m
WHITE		=	\033[1;97m

# ---------------------------------------------------------------------------- #
#   Include dependency files                                                   #
# ---------------------------------------------------------------------------- #

-include $(DEPS)