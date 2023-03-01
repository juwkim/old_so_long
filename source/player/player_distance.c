/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_distance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:44:37 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 23:19:38 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player/player_distance.h"

int	get_right_dist(t_point *p, char *map[])
{
	const int	y = p->first + BLOCK_SIZE;
	const int	x1 = (p->second + BLOCK_SIZE * 1 / 6) / BLOCK_SIZE;
	const int	x2 = (p->second + BLOCK_SIZE * 3 / 6) / BLOCK_SIZE;
	const int	x3 = (p->second + BLOCK_SIZE * 5 / 6) / BLOCK_SIZE;
	int			cur;

	cur = y;
	while (map[x1][cur / BLOCK_SIZE] != CHAR_WALL && \
			map[x2][cur / BLOCK_SIZE] != CHAR_WALL && \
			map[x3][cur / BLOCK_SIZE] != CHAR_WALL)
		cur += SEARCH_STAP;
	return (ft_min(HORIZONTAL_SPEED, cur - y));
}

int	get_left_dist(t_point *p, char *map[])
{
	const int	y = p->first;
	const int	x1 = (p->second + BLOCK_SIZE * 1 / 6) / BLOCK_SIZE;
	const int	x2 = (p->second + BLOCK_SIZE * 3 / 6) / BLOCK_SIZE;
	const int	x3 = (p->second + BLOCK_SIZE * 5 / 6) / BLOCK_SIZE;
	int			cur;

	cur = y;
	while (map[x1][cur / BLOCK_SIZE] != CHAR_WALL && \
			map[x2][cur / BLOCK_SIZE] != CHAR_WALL && \
			map[x3][cur / BLOCK_SIZE] != CHAR_WALL)
		cur -= SEARCH_STAP;
	return (ft_min(HORIZONTAL_SPEED, y - cur));
}

int	get_down_dist(t_point *p, char *map[])
{
	const int	x = p->second + BLOCK_SIZE;
	const int	y1 = (p->first + BLOCK_SIZE * 1 / 6) / BLOCK_SIZE;
	const int	y2 = (p->first + BLOCK_SIZE * 3 / 6) / BLOCK_SIZE;
	const int	y3 = (p->first + BLOCK_SIZE * 5 / 6) / BLOCK_SIZE;
	int			cur;

	cur = x;
	while (map[cur / BLOCK_SIZE][y1] != CHAR_WALL && \
			map[cur / BLOCK_SIZE][y2] != CHAR_WALL && \
			map[cur / BLOCK_SIZE][y3] != CHAR_WALL)
		cur += SEARCH_STAP;
	return (ft_min(VERTICAL_SPEED, cur - x));
}

int	get_up_dist(t_point *p, char *map[])
{
	const int	x = p->second;
	const int	y1 = (p->first + BLOCK_SIZE * 1 / 6) / BLOCK_SIZE;
	const int	y2 = (p->first + BLOCK_SIZE * 3 / 6) / BLOCK_SIZE;
	const int	y3 = (p->first + BLOCK_SIZE * 5 / 6) / BLOCK_SIZE;
	int			cur;

	cur = x;
	while (map[cur / BLOCK_SIZE][y1] != CHAR_WALL && \
			map[cur / BLOCK_SIZE][y2] != CHAR_WALL && \
			map[cur / BLOCK_SIZE][y3] != CHAR_WALL)
		cur -= SEARCH_STAP;
	return (ft_min(VERTICAL_SPEED, x - cur));
}
