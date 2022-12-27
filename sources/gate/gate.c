/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gate.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:43:20 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 01:34:34 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gate/gate.h"

int	*get_gate_image(t_game *game)
{
	static int	idx;
	static int	cnt;

	cnt = (cnt + 1) % UPDATE_CYCLE;
	if (cnt == 0 && game->count[COLLECTABLE] == 0)
		idx = min(idx + 1, GATE_NUMBER - 1);
	return (game->image[GATE][idx]);
}

void	gate_action(t_game *game)
{
	if (game->count[COLLECTABLE] == 0)
	{
		ft_printf("Success !");
		destroy(game);
	}
}

// Collisions between the gate and the player
void	gate_collision(t_player *game)
{
	const t_player	*p = &game->player;

	if (game->map[(p->a[1] + HPX) / BPX][(p->a[0] + HPX) / BPX] == 'E')
		gate_action(game);
	else if (game->map[(p->b[1] - HPX) / BPX][(p->b[0] + HPX) / BPX] == 'E')
		gate_action(game);
	else if (game->map[(p->a[1] + HPX) / BPX][(p->c[0] - HPX) / BPX] == 'E')
		gate_action(game);
	else if (game->map[(p->d[1] - HPX) / BPX][(p->c[0] - HPX) / BPX] == 'E')
		gate_action(game);
}
