/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 06:31:59 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 18:49:38 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player/player_move.h"

void	player_move_horizontal(t_player *p, char *map[])
{
	if (p->move_horizontal == MOVE_RIGHT)
		p->position.first += get_right_dist(p, map);
	else if (p->move_horizontal == MOVE_LEFT)
		p->position.first -= get_left_dist(p, map);
}

void	player_move_vertical(t_player *p, char *map[])
{
	if (p->move_vertical == MOVE_DOWN)
		p->position.second += get_down_dist(p, map);
	else if (p->move_vertical == MOVE_UP)
		p->position.second -= get_up_dist(p, map);
}

void	player_move_up(t_player *p, char *map[])
{
	if (p->move_vertical == MOVE_UP && p->jump == 0 \
			&& get_down_dist(p, map) == 0)
		p->jump = 10;
	if (p->jump > 0)
	{
		p->position.second -= get_up_dist(p, map);
		--p->jump;
		if (p->jump == 0)
			p->move_vertical = MOVE_DOWN;
	}
}

void	player_move_down(t_player *p, char *map[])
{
	if (p->move_vertical != MOVE_DOWN && p->jump == 0)
		p->position.second += get_down_dist(p, map);
}
