/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gate.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:43:20 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 08:17:12 by juwkim           ###   ########.fr       */
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

void	gate_collision(t_game *game)
{
	const int		y = game->player.position.first + BLOCK_SIZE / 2;
	const int		x = game->player.position.second + BLOCK_SIZE / 2;

	if (game->count[COLLECTABLE] == 0 && \
		game->map[x / BLOCK_SIZE][y / BLOCK_SIZE] == CHAR_EXIT)
	{
		ft_printf("Success !\n");
		destroy(game);
	}
}
