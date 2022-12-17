/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/12/16 17:43:35 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Displays a wall block
static void	draw_wall(t_so_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (i < so_long->game_height)
	{
		j = 0;
		while (j < so_long->game_width)
		{
			if (so_long->map[i][j] == '1')
				draw_block(j * BPX + so_long->window_offset.first,
					i * BPX + so_long->window_offset.second, so_long->os[1],
					so_long);
			j++;
		}
		i++;
	}
}

// Meta function for walls
void	wall(t_so_long *so_long)
{
	draw_wall(so_long);
}
