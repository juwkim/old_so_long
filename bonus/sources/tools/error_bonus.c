/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:41:11 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 08:01:12 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools/error_bonus.h"

void	error(int error_n)
{
	const char *const	error_message[4] = \
	{
		"Error\nYou must indicate only one map path!\n", \
		"Error\nUnable to open the map!\n", \
		"Error\nThe map is not in a valid format!\n", \
		"Error\nAn image could not be opened!\n"
	};

	ft_printf(error_message[error_n]);
	exit(EXIT_FAILURE);
}
