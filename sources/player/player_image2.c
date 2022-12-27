/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_image2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 07:28:15 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 07:35:34 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player/player_image2.h"

int	player_attack_sprite(t_player *player)
{
	static int	idx;

	if (player->move_horizontal == MOVE_LEFT)
	{
		if (player->last_image != 2)
			idx = 46;
		else if (45 < idx && idx < 49)
			idx++;
		else
			idx = 46;
	}
	else
	{
		if (player->last_image != 2)
			idx = 19;
		else if (18 < idx && idx < 22)
			idx++;
		else
			idx = 19;
	}
	player->last_image = 2;
	return (idx);
}

int	player_walk_sprite(t_player *player)
{
	static int	idx;

	if (player->move_horizontal == MOVE_LEFT)
	{
		if (player->last_image != 3)
			idx = 35;
		else if (34 < idx && idx < 38)
			idx++;
		else
			idx = 35;
	}
	else
	{
		if (player->last_image != 3)
			idx = 8;
		else if (7 < idx && idx < 11)
			idx++;
		else
			idx = 8;
	}
	player->last_image = 3;
	return (idx);
}

// Return player hurt sprite
int	player_hurt_sprite(t_player *player)
{
	static int	idx;

	if (player->move_horizontal == MOVE_LEFT)
	{
		if (player->last_image != 6)
			idx = 50;
		else if (49 < idx && idx < 53)
			idx++;
		else
			idx = 50;
	}
	else
	{
		if (player->last_image != 6)
			idx = 23;
		else if (22 < idx && idx < 26)
			idx++;
		else
			idx = 23;
	}
	player->last_image = 6;
	return (idx);
}

int	player_down_sprite(t_player *player)
{
	static int	idx;

	if (player->move_horizontal == MOVE_LEFT)
		idx = 45;
	else
		idx = 18;
	player->last_image = 4;
	return (idx);
}
