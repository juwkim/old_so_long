/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:45:33 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 23:19:27 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player/player.h"

void	player_update(t_game *game)
{
	game->player.last_position.first = game->player.position.first;
	game->player.last_position.second = game->player.position.second;
	player_move_horizontal(&game->player, game->map);
	player_move_up(&game->player, game->map);
	player_move_down(&game->player, game->map);
	player_move_count_update(game);
	player_draw(game, &game->player);
}

void	player_move_count_update(t_game *game)
{
	if (!is_equal(game->player.last_position, game->player.position))
		++game->count[MOVE];
}

// Draw the player block on the screen
void	player_draw(t_game *game, t_player *p)
{
	game->offset.first = \
	ft_max(ft_min(game->offset.first, \
	WINDOW_WIDTH - 2 * BLOCK_SIZE - p->position.first), \
	BLOCK_SIZE - p->position.first);
	game->offset.second = \
	ft_max(ft_min(game->offset.second, \
	WINDOW_HEIGHT - 2 * BLOCK_SIZE - p->position.second), \
	BLOCK_SIZE - p->position.second);
	mlx_put_image_to_window(game->mlx, game->window,
		get_player_image(game, &game->player),
		p->position.first + game->offset.first,
		p->position.second + game->offset.second);
}
