/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_distance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:44:37 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 04:58:05 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// Return the distance between the player and the nearest obstacle on the right
int	get_prwc(t_player p, char *map[])
{
	int	dist_coll;

	if (map[(p->c[1] + HPX + EHPX) / BPX][(p->c[0]) / BPX + 1] == '1' ||
	m[(p->d[1]) / BPX][(p->d[0]) / BPX + 1] == '1')
	{
		if (m[(p->c[1] + HPX) / BPX][(p->c[0] - HPX) / BPX] == '1' ||
			m[p->d[1] / BPX][(p->d[0] - HPX) / BPX] == '1')
			return (-(HPX + 10));
		dist_coll = BPX + (BPX * ((p->c[0]) / BPX) - p->c[0]) - 1;
		return (min(MPX, dist_coll));
	}
	if (m[(p->c[1] + HPX + EHPX) / BPX][(p->c[0] - HPX + EHPX) / BPX] == '1' ||
	m[p->d[1] / BPX][(p->d[0] - HPX + EHPX) / BPX] == '1')
		return (-(HPX + EHPX + 5));
	return (MPX);
}

// Return the distance between the player and the nearest obstacle on the left
int	get_plwc(t_game *game)
{
	int			dist_coll;
	t_player	*p;
	char		**m;

	p = &game->player;
	m = game->map;
	if (m[(p->a[1] + HPX + EHPX) / BPX][(p->a[0]) / BPX -1] == '1' ||
	m[(p->b[1]) / BPX][(p->b[0]) / BPX -1] == '1')
	{
		if (m[(p->a[1] + HPX) / BPX][(p->a[0] + HPX) / BPX] == '1' ||
		m[p->b[1] / BPX][(p->b[0] + HPX) / BPX] == '1')
			return (-(HPX + 10));
		dist_coll = p->a[0] - (BPX * ((p->a[0]) / BPX));
		if (dist_coll > MPX)
			return (MPX);
		return (dist_coll);
	}
	if (m[(p->a[1] + HPX + EHPX) / BPX][(p->a[0] + HPX + EHPX) / BPX] == '1' ||
	m[p->b[1] / BPX][(p->b[0] + HPX + EHPX) / BPX] == '1')
		return (-(HPX + EHPX + 5));
	return (MPX);
}

// Return the distance between the player and the nearest obstacle on the down 
// (ground)
int	get_pgwc(t_game *game)
{
	int			dist_coll;
	t_player	*p;

	p = &game->player;
	if (game->map[(p->b[1]) / BPX +1][(p->b[0] + HPX) / BPX] == '1' ||
	game->map[(game->player.d[1]) / BPX +1]
	[(p->d[0] - HPX) / BPX] == '1')
	{
		dist_coll = (BPX * ((p->b[1]) / BPX +1)) - p->b[1] -1;
		if (dist_coll > GPX)
			return (GPX);
		return (dist_coll);
	}
	return (GPX);
}

// Return the distance between the player and the nearest obstacle on the down
int	get_pdwc(t_game *game)
{
	int			dist_coll;
	t_player	*p;

	p = &game->player;
	if (game->map[(p->b[1]) / BPX +1][(p->b[0] + HPX) / BPX] == '1' ||
	game->map[(game->player.d[1]) / BPX +1]
	[(p->d[0] - HPX) / BPX] == '1')
	{
		dist_coll = (BPX * ((p->b[1]) / BPX +1)) - p->b[1] -1;
		if (dist_coll > DPX)
			return (DPX);
		return (dist_coll);
	}
	return (DPX);
}

// Return the distance between the player and the nearest obstacle on the top
// (jump)
int	get_pjwc(t_game *game)
{
	int			dist_coll;
	t_player	*p;

	p = &game->player;
	if (game->map[(p->a[1] + 1) / BPX -1][(p->a[0] + HPX) / BPX] == '1' ||
	game->map[(p->c[1] + 1) / BPX - 1][(p->c[0] - HPX) / BPX] == '1')
	{
		dist_coll = p->b[1] - (BPX * ((p->b[1] + 1) / BPX)) - 1 + 2;
		if (dist_coll > JPX)
			return (JPX);
		return (dist_coll);
	}
	if (game->map[(p->a[1]) / BPX][(p->a[0] + HPX) / BPX] == '1' ||
	game->map[(p->c[1]) / BPX][(p->c[0] - HPX) / BPX] == '1')
		return (-(HPX));
	return (JPX);
}
