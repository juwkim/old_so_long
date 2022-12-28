/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_distance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:44:37 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 16:08:21 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player/player_distance.h"

int	get_right_dist(t_player *p, char *map[])
{
	const int	first = p->position.first + BPX;
	const int	second = (p->position.second + BPX) / BPX;

	if (map[second][first / BPX] == CHAR_WALL)
	{
		if (map[second][(first - HPX) / BPX] == CHAR_WALL)
			return (-EHPX);
		return (ft_min(MPX, BPX - first % BPX));
	}
	return (MPX);
}

int	get_left_dist(t_player *p, char *map[])
{
	const int	first = p->position.first;
	const int	second = (p->position.second + BPX) / BPX;

	if (map[second][first / BPX] == CHAR_WALL)
	{
		if (map[second][(first + HPX) / BPX] == CHAR_WALL)
			return (-EHPX);
		return (ft_min(MPX, BPX - first % BPX));
	}
	return (MPX);
}

int	get_down_dist(t_player *p, char *map[])
{
	const int	first = p->position.first;
	const int	second = p->position.second / BPX;

	if (map[second + 1][first / BPX] == CHAR_WALL ||
		map[second + 2][(first - HPX) / BPX] == CHAR_WALL)
		return (ft_min(GPX, BPX - second % BPX));
	return (GPX);
}

int	get_up_dist(t_player *p, char *map[])
{
	const int	first = p->position.first;
	const int	second = p->position.second / BPX;

	if (map[second - 1][first / BPX] == CHAR_WALL ||
		map[second - 2][(first + HPX) / BPX] == CHAR_WALL)
		return (ft_min(JPX, BPX - second % BPX));
	return (JPX);
}
