/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 01:52:00 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 23:20:20 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/collectable.h"

int	*get_collectable_image(t_game *game)
{
	static int	idx;
	static int	cnt;

	cnt = (cnt + 1) % COLLECTABLE_UPDATE_CYCLE;
	if (cnt == 0)
		idx = (idx + 1) % COIN_NUMBER;
	return (game->image[COIN][idx]);
}

void	collectable_collision(t_game *game)
{
	const int		y = game->player.position.first + BLOCK_SIZE / 2;
	const int		x = game->player.position.second + BLOCK_SIZE / 2;

	if (game->map[x / BLOCK_SIZE][y / BLOCK_SIZE] == CHAR_COLLECTABLE)
	{
		game->map[x / BLOCK_SIZE][y / BLOCK_SIZE] = CHAR_EMPTY;
		--game->count[COLLECTABLE];
	}
}
