/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 06:31:59 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 05:20:57 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player/player_move.h"

void	player_move_horizontal(t_player *p, char *map[])
{
	if (p->move_horizontal == MOVE_RIGHT)
	{
		p->position.first += get_right_dist(&p->position, map);
		p->last_move = p->move_horizontal;
	}
	else if (p->move_horizontal == MOVE_LEFT)
	{
		p->position.first -= get_left_dist(&p->position, map);
		p->last_move = p->move_horizontal;
	}
	p->position.first = ft_max(p->position.first, BLOCK_SIZE);
}

void	player_move_up(t_player *p, char *map[])
{
	if (p->jump > 0)
	{
		p->position.second -= get_up_dist(&p->position, map);
		p->position.second = ft_max(p->position.second, BLOCK_SIZE);
		--p->jump;
		if (p->jump == 0)
			p->move_vertical = MOVE_DOWN;
	}
}

void	player_move_down(t_player *p, char *map[])
{
	const int	dist = get_down_dist(&p->position, map);

	if (p->jump == 0 && dist)
		p->position.second += dist;
	else
		p->move_vertical = MOVE_STAY;
}
