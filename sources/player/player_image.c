/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 06:54:32 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 07:08:53 by juwkim           ###   ########.fr       */
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


# recode jump in player
int	player_jump_image(t_player *player)
{
	if (player->move_horizontal == MOVE_LEFT)
	{
		if (game->player.jump > 1)
			i = 39;
		else if (game->player.jump <= 1)
			i = 40;
	}
	else
	{
		if (game->player.jump > 1)
			i = 12;
		else if (game->player.jump <= 1)
			i = 13;
	}
	*last_anim = 1;
	return (i);
}

// Return player failling sprite
int	player_failling_sprite(t_player *player)
{
	static int	i;

	if (game->player.direction == 0)
		i = 44;
	else
		i = 17;
	*last_anim = 5;
	return (i);
}

// Return player stay sprite
int	player_stay_sprite(t_player *player)
{
	static int	i;

	if (game->player.direction == 0)
	{
		if (*last_anim != 7)
			i = 27;
		else if (i > 26 && i < 34)
			i++;
		else
			i = 27;
	}
	else
	{
		if (*last_anim != 7)
			i = 0;
		else if (i > -1 && i < 7)
			i++;
		else
			i = 0;
	}
	*last_anim = 7;
	return (i);
}

int	player_attack_sprite(it_player *player)
{
	static int	i;

	if (game->player.direction == 0)
	{
		if (*last_anim != 2)
			i = 46;
		else if (i > 45 && i < 49)
			i++;
		else
			i = 46;
	}
	else
	{
		if (*last_anim != 2)
			i = 19;
		else if (i > 18 && i < 22)
			i++;
		else
			i = 19;
	}
	*last_anim = 2;
	return (i);
}

// Return player walk sprite
int	player_walk_sprite(t_player *player)
{
	static int	i;

	if (game->player.direction == 0)
	{
		if (*last_anim != 3)
			i = 35;
		else if (i > 34 && i < 38)
			i++;
		else
			i = 35;
	}
	else
	{
		if (*last_anim != 3)
			i = 8;
		else if (i > 7 && i < 11)
			i++;
		else
			i = 8;
	}
	*last_anim = 3;
	return (i);
}

// Return player hurt sprite
int	player_hurt_sprite(t_player *player)
{
	static int	i;

	if (game->player.direction == 0)
	{
		if (*last_anim != 6)
			i = 50;
		else if (i > 49 && i < 53)
			i++;
		else
			i = 50;
	}
	else
	{
		if (*last_anim != 6)
			i = 23;
		else if (i > 22 && i < 26)
			i++;
		else
			i = 23;
	}
	*last_anim = 6;
	return (i);
}

// Return player down sprite
int	player_down_sprite(t_player *player)
{
	static int	i;

	if (game->player.direction == 0)
		i = 45;
	else
		i = 18;
	*last_anim = 4;
	return (i);
}