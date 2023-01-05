/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 02:19:53 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 07:30:43 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/draw.h"

void	draw_block(t_game *game, void *block, int first, int second)
{
	const int	x = first * BLOCK_SIZE + game->offset.first;
	const int	y = second * BLOCK_SIZE + game->offset.second;

	if (x < -BLOCK_SIZE || y < -BLOCK_SIZE || \
		x > WINDOW_WIDTH || y > WINDOW_HEIGHT)
		return ;
	mlx_put_image_to_window(game->mlx, game->window, block, x, y);
}

void	draw_background(t_game *game)
{
	int	second;
	int	first;

	mlx_clear_window(game->mlx, game->window);
	second = 0;
	while (second < game->map_size.second)
	{
		first = 0;
		while (first < game->map_size.first)
		{	
			if (game->map[second][first] == CHAR_WALL)
				draw_block(game, game->image[BLOCK][WALL_IDX], first, second);
			else
				draw_block(game, game->image[BLOCK][BLOCK_IDX], first, second);
			if (game->map[second][first] == CHAR_COLLECTABLE)
				draw_block(game, get_collectable_image(game), first, second);
			else if (game->map[second][first] == CHAR_EXIT)
				draw_block(game, get_gate_image(game), first, second);
			++first;
		}
		++second;
	}
}
