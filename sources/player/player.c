/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:45:33 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 04:50:41 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player/player.h"

void	player_update(t_game *game)
{
	game->player.last_position.first = game->player.position.first;
	game->player.last_position.second = game->player.position.second;
	player_move_horizontal(game);
	player_move_vertical(game);
	player_move_diagonal(game);
	player_jump(game);
	player_gravity(game);
	player_move_count_update(game);
	player_draw(game);
}

void	player_move_count_update(t_game *game)
{
	if (!is_equal(game->player.last_position, game->player.position))
		++game->count[MOVE];
}

// Draw the player block on the screen
void	player_draw(t_game *game)
{
	const t_player	*p = &game->player;
	const int		first = p->position.first + game->offset_window.first;
	const int		second = p->position.second + game->offset_window.second;

	if (p->position.first < (64 * 2))
		game->offset_window.first = 0;
	else if (first < 128)
		game->offset_window.first = (64 * 2) - p->position.first;
	else if (first > ((64 * 17) + 76))
		game->offset_window.first = (64 * 17) + 76 - p->position.first;
	if (p->position.second < (64 * 2))
		game->offset_window.second = 0;
	else if (second < (64 * 2))
		game->offset_window.second = (64 * 2) - p->position.second;
	else if (second > (64 * 8) + 48)
		game->offset_window.second = (64 * 8) + 48 - p->position.second;
	mlx_put_image_to_window(game->mlx, game->window,
		get_player_image(game),
		p->position.first + game->offset_window.first + \
		game->offset_game.first, p->position.second + \
		game->offset_window.second + game->offset_game.second);
}
