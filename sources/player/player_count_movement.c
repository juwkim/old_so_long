/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_count_movement.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/12/16 17:25:02 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Count player movement
void	player_count_movement(t_so_long *so_long)
{
	if (so_long->player.lpp.first != so_long->player.position.first || \
		so_long->player.lpp.second != so_long->player.position.second)
		so_long->move_count++;
}
