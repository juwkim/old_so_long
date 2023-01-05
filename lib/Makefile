# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 05:18:16 by juwkim            #+#    #+#              #
#    Updated: 2023/01/06 08:13:33 by juwkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ARFLAGS		= rsc
NAME		= lib.a
libs		= ft_printf.a get_next_line.a libft.a
libmlx  	= libmlx.dylib

all		: $(NAME)
$(NAME)	: $(libmlx) $(libs)

ft_printf.a:
	@make -C ./ft_printf
	@cp ./ft_printf/ft_printf.a ./ft_printf.a

get_next_line.a:
	@make -C ./get_next_line
	@cp ./get_next_line/get_next_line.a ./get_next_line.a

libft.a:
	@make -C ./libft
	@cp ./libft/libft.a ./libft.a

libmlx.dylib:
	@make -C ./minilibx-mms
	@cp ./minilibx-mms/libmlx.dylib ../libmlx.dylib

clean:
	@make clean -C ./ft_printf
	@make clean -C ./get_next_line
	@make clean -C ./libft
	@make clean -C ./minilibx-mms

fclean:
	@$(RM) $(libs) $(libmlx)
	@make fclean -C ./ft_printf
	@make fclean -C ./get_next_line
	@make fclean -C ./libft
	@make fclean -C ./minilibx-mms

re: fclean
	@make all

.PHONY:	all clean fclean re