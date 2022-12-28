/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 01:52:00 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 17:58:50 by juwkim           ###   ########.fr       */
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

void	collectable_action(t_game *game, int x, int y)
{
	if (game->map[x][y] == CHAR_COLLECTABLE)
	{
		game->map[x][y] = CHAR_EMPTY;
		--game->count[COLLECTABLE];
	}
}

void	collectable_collision(t_game *game)
{
	const int		y = game->player.position.first;
	const int		x = game->player.position.second;

	collectable_action(game, (x + HPX) / BPX, (y + HPX) / BPX);
	collectable_action(game, (x + BPX - HPX) / BPX, (y + HPX) / BPX);
	collectable_action(game, (x + HPX) / BPX, (y + BPX - HPX) / BPX);
	collectable_action(game, (x + BPX - HPX) / BPX, (y + BPX - HPX) / BPX);
}
