/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/12/16 19:30:13 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "error.h"

void	error(int error_n)
{
	const char *const	error_message[4] = \
	{"Error: You must indicate only one map path !\n", \
	"Error: Unable to open the map !\n", \
	"Error: The map is not in a valid format !\n", \
	"Error: A sprite could not be opened !\n"};

	ft_printf(error_message[error_n]);
	exit(EXIT_FAILURE);
}
