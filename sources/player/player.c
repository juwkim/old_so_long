/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/12/15 15:40:04 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// main player function
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
