/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:43:03 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/27 23:41:52 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
# define BLOCK 0

void	draw_background(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == '0' || game->map[i][j] == 'M'
			|| game->map[i][j] == 'P' || game->map[i][j] == 'C' )
				draw_block(j * BPX + game->offset_window.first,
					i * BPX + game->offset_window.second, game->image[OTHER][BLOCK],
					game);
			j++;
		}
		i++;
	}
}