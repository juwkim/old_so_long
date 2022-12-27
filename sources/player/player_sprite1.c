/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_sprite1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:45:15 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 04:46:29 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// Return player failling sprite
int	player_failling_sprite(int *last_anim, t_game *game)
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
int	player_stay_sprite(int *last_anim, t_game *game)
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

// Return sprite depending on the player's state
static int	player_sprite_pos(int atk_progress, int hurt_progress,
int *last_anim, t_game *game)
{
	if (game->player.jump != 0)
		return (player_jumb_sprite(last_anim, game));
	else if (atk_progress > 0)
		return (player_attack_sprite(last_anim, game));
	else if (hurt_progress > 0)
		return (player_hurt_sprite(last_anim, game));
	else if (game->player.action_code[0] == 2 || game->player.action_code[1] == 2 || \
	game->player.action_code[0] == 1 || game->player.action_code[1] == 1)
		return (player_walk_sprite(last_anim, game));
	else if ((game->player.action_code[0] == 4 || game->player.action_code[1] == 4) && \
	get_pgwc(game) > 0)
		return (player_down_sprite(last_anim, game));
	else if (game->player.jump == 0 && get_pgwc(game) > 0)
		return (player_failling_sprite(last_anim, game));
	else
		return (player_stay_sprite(last_anim, game));
}

// Get the sprite that corresponds to the correct animation step
int	*get_player_image(t_game *game)
{
	static int	arr_pos;
	static int	last_anim;
	static int	anim_inter;
	static int	atk_progress;
	static int	hurt_progress;

	if (game->player.action_code[2] == 5)
		atk_progress = 5;
	if (game->player.tick_life == 1)
		hurt_progress = 5;
	if (anim_inter == 5)
	{
		anim_inter = 0;
		if (atk_progress > 0)
			atk_progress--;
		if (hurt_progress > 0)
			hurt_progress--;
		arr_pos = player_sprite_pos(atk_progress, hurt_progress, \
		&last_anim, game);
	}
	else
		anim_inter++;
	return (game->ps[arr_pos]);
}
