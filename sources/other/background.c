/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:43:03 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/23 13:43:07 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// Displays a background block
static void	draw_background(t_so_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (i < so_long->game_height)
	{
		j = 0;
		while (j < so_long->game_width)
		{
			if (so_long->map[i][j] == '0' || so_long->map[i][j] == 'M'
			|| so_long->map[i][j] == 'P' || so_long->map[i][j] == 'C' )
				draw_block(j * BPX + so_long->window_offset.first,
					i * BPX + so_long->window_offset.second, so_long->os[0],
					so_long);
			j++;
		}
		i++;
	}
}

// Meta function for background
void	background(t_so_long *so_long)
{
	draw_background(so_long);
}
