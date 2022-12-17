# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 05:18:16 by juwkim            #+#    #+#              #
#    Updated: 2022/12/16 20:55:26 by juwkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
ARFLAGS		= rsc
SRCS		= $(wildcard *.c)
OBJS		= $(SRCS:.c=.o)
DEPS		= $(SRCS:.c=.d)
-include $(DEPS)

NAME 		= ft_printf.a

all 	: 	$(NAME)

$(NAME)	: 	$(OBJS)
	@$(AR) $(ARFLAGS) $@ $^
	@echo "\n${GREEN}> Compilation of the ft_printf is success 🎉${END}"

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $^
	@echo -n .

clean	:
	@$(RM) $(OBJS)

fclean	:	clean
	@$(RM) $(NAME)

re		:	fclean
	@make all

.PHONY	:	all clean fclean re

# minimal color codes
END=$'\x1b[0m
BOLD=$'\x1b[1m
UNDER=$'\x1b[4m
REV=$'\x1b[7m
GREY=$'\x1b[30m
RED=$'\x1b[31m
GREEN=$'\x1b[32m
YELLOW=$'\x1b[33m
BLUE=$'\x1b[34m
PURPLE=$'\x1b[35m
CYAN=$'\x1b[36m
WHITE=$'\x1b[37m