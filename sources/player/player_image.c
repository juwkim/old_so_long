/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 06:54:32 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 13:32:58 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player/player_image.h"

int	*get_player_image(t_game *game)
{
	static int	cnt;
	static int	idx;
	static int	attack_progress;
	static int	hurt_progress;

	if (game->player.attack == TRUE)
		attack_progress = 5;
	if (game->player.tick_life == 1)
		hurt_progress = 5;
	cnt = (cnt + 1) % UPDATE_CYCLE;
	if (cnt == 0)
	{
		attack_progress = min(attack_progress - 1, 0);
		hurt_progress = min(hurt_progress - 1, 0);
		idx = player_sprite_pos(game, attack_progress, hurt_progress);
	}
	return (game->image[CAT][idx]);
}

int	player_sprite_pos(t_game *game, int attack_progress, int hurt_progress)
{
	const t_player	*player = &game->player;

	if (player->move_vertical == MOVE_UP)
		return (player_jump_image(player));
	else if (attack_progress)
		return (player_attack_sprite(player));
	else if (hurt_progress)
		return (player_hurt_sprite(player));
	else if (player->move_horizontal != MOVE_STAY)
		return (player_walk_sprite(player));
	else if (player->move_vertical == MOVE_DOWN \
				&& get_down_dist(player, game->map) > 0)
		return (player_down_sprite(player));
	else if (player->move_vertical == MOVE_STAY \
				&& get_down_dist(player, game->map) > 0)
		return (player_failling_sprite(player));
	else
		return (player_stay_sprite(player));
}

int	player_jump_image(t_player *player)
{
	int	idx;

	if (player->move_horizontal == MOVE_LEFT)
	{
		if (player->jump > 1)
			idx = 39;
		else
			idx = 40;
	}
	else
	{
		if (player->jump > 1)
			idx = 12;
		else
			idx = 13;
	}
	player->last_image = 1;
	return (idx);
}

// Return player failling sprite
int	player_failling_sprite(t_player *player)
{
	int	idx;

	if (player->move_horizontal == MOVE_LEFT)
		idx = 44;
	else
		idx = 17;
	player->last_image = 5;
	return (idx);
}

// Return player stay sprite
int	player_stay_sprite(t_player *player)
{
	static int	idx;

	if (player->move_horizontal == MOVE_LEFT)
	{
		if (player->last_image != 7)
			idx = 27;
		else if (26 < idx && idx < 34)
			idx++;
		else
			idx = 27;
	}
	{
		if (player->last_image != 7)
			idx = 0;
		else if (-1 < idx && idx < 7)
			idx++;
		else
			idx = 0;
	}
	player->last_image = 7;
	return (idx);
}
