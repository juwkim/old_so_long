/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gate.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:43:20 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 06:41:27 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gate/gate.h"

int	*get_gate_image(t_game *game)
{
	static int	idx;
	static int	cnt;

	cnt = (cnt + 1) % UPDATE_CYCLE;
	if (cnt == 0 && game->count[COLLECTABLE_IDX] == 0)
		idx = min(idx + 1, GATE_NUMBER - 1);
	return (game->image[GATE][idx]);
}

void	gate_action(t_game *game, int first, int second)
{
	if (game->count[COLLECTABLE_IDX] == 0 && game->map[first][second] == 'E')
	{
		ft_printf("Success !");
		destroy(game);
	}
}

void	gate_collision(t_game *game)
{
	const int		y = game->player.position.first;
	const int		x = game->player.position.second;

	gate_action(game, (x + HPX) / BPX, (y + HPX) / BPX);
	gate_action(game, (x + BPX - HPX) / BPX, (y + HPX) / BPX);
	gate_action(game, (x + HPX) / BPX, (y + BPX - HPX) / BPX);
	gate_action(game, (x + BPX - HPX) / BPX, (y + BPX - HPX) / BPX);
}
