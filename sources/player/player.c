/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:45:33 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/27 23:41:34 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	player(t_game *game)
{
	game->player.lpp.first = game->player.position.first;
	game->player.lpp.second = game->player.position.second;
	player_jump(game);
	player_gravity(game);
	player_move_y(game);
	player_move_z(game);
	player_move_d(game);
	player_count_movement(game);
	player_draw(game);
}
