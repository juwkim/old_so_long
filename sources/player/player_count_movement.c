/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_count_movement.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:44:20 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/23 13:44:25 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// Count player movement
void	player_count_movement(t_so_long *so_long)
{
	if (so_long->player.lpp.first != so_long->player.position.first || \
		so_long->player.lpp.second != so_long->player.position.second)
		so_long->move_count++;
}
