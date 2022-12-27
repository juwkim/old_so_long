/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:43:45 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/27 23:46:52 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// Displays a wall block
void	draw_wall(t_so_long *so_long)
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
