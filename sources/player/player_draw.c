/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/12/16 17:39:38 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Draw the player block on the screen
void	player_draw(t_so_long *so_long)
{
	int					screen_pp[2];
	t_player *const		p = &so_long->player;

	screen_pp[0] = p->position.first + so_long->window_offset.first;
	screen_pp[1] = p->position.second + so_long->window_offset.second;
	if (p->position.second < (64 * 2))
		so_long->window_offset.second = 0;
	else if (screen_pp[1] > (512 + 48))
		so_long->window_offset.second = -p->position.second + (64 * 8) + 48;
	else if (screen_pp[1] < 128)
		so_long->window_offset.second = -p->position.second + (64 * 2);
	if (p->position.first < (64 * 2))
		so_long->window_offset.first = 0;
	else if (screen_pp[0] > (1088 + 76))
		so_long->window_offset.first = -p->position.first + (64 * 17) + 76;
	else if (screen_pp[0] < 128)
		so_long->window_offset.first = -p->position.first + (64 * 2);
	mlx_put_image_to_window(so_long->mlx, so_long->window,
		get_player_sprite(so_long),
		p->position.first + so_long->window_offset.first + \
		so_long->game_offset.first, p->position.second + \
		so_long->window_offset.second + so_long->game_offset.second);
}
