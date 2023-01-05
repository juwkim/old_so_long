/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 06:54:32 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 04:22:36 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player/player_image.h"

int	*get_player_image(t_game *game, t_player *player)
{
	static int	cnt;
	static int	idx;

	cnt = (cnt + 1) % UPDATE_CYCLE;
	if (cnt == 0)
	{
		if (player->move_vertical == MOVE_UP)
			idx = get_jump_image(player);
		else if (player->move_horizontal != MOVE_STAY)
			idx = get_walk_image(player);
		else if (player->move_vertical == MOVE_DOWN \
				&& get_down_dist(&player->position, game->map) > 0)
			idx = get_down_image(player);
		else
			idx = get_stay_image(player);
	}
	return (game->image[CAT][idx]);
}

int	get_jump_image(t_player *player)
{
	int	idx;

	if (player->move_horizontal == MOVE_LEFT)
	{
		if (player->jump)
			idx = 39;
		else
			idx = 40;
	}
	else
	{
		if (player->jump)
			idx = 12;
		else
			idx = 13;
	}
	return (idx);
}

int	get_down_image(t_player *player)
{
	int	idx;

	if (player->move_horizontal == MOVE_LEFT)
		idx = 44;
	else
		idx = 17;
	return (idx);
}

int	get_stay_image(t_player *player)
{
	static int	idx;

	if (player->last_move == MOVE_RIGHT)
	{
		if (0 <= idx && idx <= 6)
			idx++;
		else
			idx = 0;
	}
	else
	{
		if (27 <= idx && idx <= 33)
			idx++;
		else
			idx = 27;
	}
	return (idx);
}

int	get_walk_image(t_player *player)
{
	static int	idx;

	if (player->move_horizontal == MOVE_LEFT)
	{
		if (35 <= idx && idx <= 37)
			idx++;
		else
			idx = 35;
	}
	else
	{
		if (8 <= idx && idx <= 10)
			idx++;
		else
			idx = 8;
	}
	return (idx);
}
