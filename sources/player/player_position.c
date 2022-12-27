/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:45:08 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 00:18:47 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "player/player.h"

// Setting player collision points
void	player_position(t_player *player)
{
	const int	x = player->position.first;
	const int	y = player->position.second;

	player->top_left.first = x;
	player->top_left.second = y;
	player->top_right.first = x;
	player->top_right.second = y + BPX;
	player->btm_left.first = x + BPX;
	player->btm_left.second = y;
	player->btm_right.first = x + BPX;
	player->btm_right.second = y + BPX;
}
