/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_distance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:44:37 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 19:57:50 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player/player_distance.h"

int	get_right_dist(t_player *p, char *map[])
{
	const int	y = p->position.first + BPX;
	const int	x1 = p->position.second / BPX;
	const int	x2 = (p->position.second + BPX / 3) / BPX;
	const int	x3 = (p->position.second + BPX * 2 / 3) / BPX;
	int			cur;

	cur = y;
	while (map[x1][cur / BPX] != CHAR_WALL && \
			map[x2][cur / BPX] != CHAR_WALL && \
			map[x3][cur / BPX] != CHAR_WALL)
		cur += 10;
	return (ft_min(8, cur - y));
}

int	get_left_dist(t_player *p, char *map[])
{
	const int	y = p->position.first;
	const int	x1 = p->position.second / BPX;
	const int	x2 = (p->position.second + BPX / 3) / BPX;
	const int	x3 = (p->position.second + BPX * 2 / 3) / BPX;
	int			cur;

	cur = y;
	while (map[x1][cur / BPX] != CHAR_WALL && \
			map[x2][cur / BPX] != CHAR_WALL && \
			map[x3][cur / BPX] != CHAR_WALL)
		cur -= 10;
	return (ft_min(8, y - cur));
}

int	get_down_dist(t_player *p, char *map[])
{
	const int	x = p->position.second + BPX;
	const int	y1 = p->position.first / BPX;
	const int	y2 = (p->position.first + BPX / 3) / BPX;
	const int	y3 = (p->position.first + BPX * 2 / 3) / BPX;
	int			cur;

	cur = x;
	while (map[cur / BPX][y1] != CHAR_WALL && \
			map[cur / BPX][y2] != CHAR_WALL && \
			map[cur / BPX][y3] != CHAR_WALL)
		cur += 10;
	return (ft_min(8, cur - x));
}

int	get_up_dist(t_player *p, char *map[])
{
	const int	x = p->position.second;
	const int	y1 = p->position.first / BPX;
	const int	y2 = (p->position.first + BPX / 3) / BPX;
	const int	y3 = (p->position.first + BPX * 2 / 3) / BPX;
	int			cur;

	cur = x;
	while (map[cur / BPX][y1] != CHAR_WALL && \
			map[cur / BPX][y2] != CHAR_WALL && \
			map[cur / BPX][y3] != CHAR_WALL)
		cur -= 10;
	return (ft_min(8, x - cur));
}
