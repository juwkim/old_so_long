/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:43:03 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 01:02:53 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_background.h"

void	draw_block(t_game *game, void *block, int first, int second)
{
	const int	x = first * BPX + game->offset_window.first;
	const int	y = second * BPX + game->offset_window.second;

	if (x < -BPX || y < -BPX || x > WINDOW_WIDTH || y > WINDOW_HEIGHT)
		return ;
	mlx_put_image_to_window(game->mlx, game->window, block, first, second);
}

void	draw_background(t_game *game)
{
	int	second;
	int	first;

	second = 0;
	while (second < game->map_size.second)
	{
		first = 0;
		while (first < game->map_size.first)
		{
			if (game->map[second][first] == '1')
				draw_block(game, first, second, game->image[OTHER][WALL]);
			else
				draw_block(game, first, second, game->image[OTHER][BLOCK]);
			if (game->map[second][first] == 'C')
				draw_block(game, first, second, get_item_sprite(game));
			else if (game->map[second][first] == 'E')
				draw_block(game, first, second, get_gate_sprite(game));
			++first;
		}
		++second;
	}
}
