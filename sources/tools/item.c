/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:43:34 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 01:06:56 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// Get the sprite that corresponds to the correct animation step
int	*get_item_sprite(t_so_long *so_long)
{
	static int	arr_pos;
	static int	anim_inter;

	if (anim_inter >= so_long->collectable_count * 5)
	{
		anim_inter = 0;
		if (arr_pos < 4)
			arr_pos++;
		else
			arr_pos = 0;
	}
	else
		anim_inter++;
	return (so_long->cs[arr_pos]);
}

// Action triggered during collision with the player
static void	item_action(t_so_long *so_long)
{
	so_long->collectable_count--;
}

// Collision system with the player
static void	item_collision(t_so_long *so_long)
{
	t_player	*p;

	p = &so_long->player;
	if (so_long->map[(p->a[1] + HPX) / BPX][(p->a[0] + HPX) / BPX] == 'C')
	{
		so_long->map[(p->a[1] + HPX) / BPX][(p->a[0] + HPX) / BPX] = '0';
		item_action(so_long);
	}
	else if (so_long->map[(p->b[1] - HPX) / BPX][(p->b[0] + HPX) / BPX] == 'C')
	{
		so_long->map[(p->b[1] + HPX) / BPX][(p->b[0] + HPX) / BPX] = '0';
		item_action(so_long);
	}
	else if (so_long->map[(p->a[1] + HPX) / BPX][(p->c[0] - HPX) / BPX] == 'C')
	{
		so_long->map[(p->a[1] + HPX) / BPX][(p->c[0] - HPX) / BPX] = '0';
		item_action(so_long);
	}
	else if (so_long->map[(p->d[1] - HPX) / BPX][(p->c[0] - HPX) / BPX] == 'C')
	{
		so_long->map[(p->d[1] - HPX) / BPX][(p->d[0] - HPX) / BPX] = '0';
		item_action(so_long);
	}
}