/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gate.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:43:20 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 17:58:25 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/gate.h"

int	*get_gate_image(t_game *game)
{
	static int	idx;
	static int	cnt;

	cnt = (cnt + 1) % GATE_UPDATE_CYCLE;
	if (cnt == 0 && game->count[COLLECTABLE] == 0)
		idx = ft_min(idx + 1, GATE_NUMBER - 1);
	return (game->image[GATE][idx]);
}

void	gate_action(t_game *game, int x, int y)
{
	if (game->count[COLLECTABLE] == 0 && game->map[x][y] == CHAR_EXIT)
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
