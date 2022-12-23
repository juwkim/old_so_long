/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:45:33 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/23 13:45:37 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	player(t_so_long *so_long)
{
	so_long->player.lpp.first = so_long->player.position.first;
	so_long->player.lpp.second = so_long->player.position.second;
	player_jump(so_long);
	player_gravity(so_long);
	player_move_y(so_long);
	player_move_z(so_long);
	player_move_d(so_long);
	player_count_movement(so_long);
	player_draw(so_long);
}
