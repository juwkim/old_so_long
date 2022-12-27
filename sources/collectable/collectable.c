/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 01:52:00 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 03:02:54 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collectable/collectable.h"

int	*get_collectable_image(t_game *game)
{
	static int	idx;
	static int	cnt;

	cnt = (cnt + 1) % UPDATE_CYCLE;
	if (cnt == 0)
		idx = (idx + 1) % COIN_NUMBER;
	return (game->image[COIN][idx]);
}

void	collectable_action(t_game *game, int first, int second)
{
	if (game->map[first][second] == 'C')
	{
		game->map[first][second] == '0';
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
