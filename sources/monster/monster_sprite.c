/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_sprite1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:42:37 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/23 13:42:41 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// Return death move sprite
static int	monster_death_sprite(t_monster *m)
{
	if (m->la != 3)
		m->ap = 0;
	m->la = 3;
	if (m->direction == 1)
	{
		if (m->ap > 6 && m->ap < 10)
			m->ap++;
		else
			m->ap = 7;
	}
	else
	{
		if (m->ap > 17 && m->ap < 21)
			m->ap++;
		else
			m->ap = 18;
	}
	return (m->ap);
}

// Return attack move sprite
static int	monster_attack_sprite(t_monster *m)
{
	if (m->la != 2)
		m->ap = 0;
	m->la = 2;
	if (m->direction == 1)
	{
		if (m->ap > 2 && m->ap < 6)
			m->ap++;
		else
			m->ap = 3;
	}
	else
	{
		if (m->ap > 13 && m->ap < 17)
			m->ap++;
		else
			m->ap = 14;
	}
	return (m->ap);
}

// Return monster move sprite
static int	monster_move_sprite(t_monster *m)
{
	if (m->la != 1)
		m->ap = 0;
	m->la = 1;
	if (m->direction == 1)
	{
		if (m->ap > -1 && m->ap < 3)
			m->ap++;
		else
			m->ap = 0;
	}
	else
	{
		if (m->ap > 10 && m->ap < 14)
			m->ap++;
		else
			m->ap = 11;
	}
	return (m->ap);
}

// Return sprite depending on the monster's state
static void	monster_sprite_pos(t_monster *m)
{
	if (m->td > 0)
		monster_death_sprite(m);
	else if (m->ta > 0)
		monster_attack_sprite(m);
	else
		monster_move_sprite(m);
}

// Get the sprite that corresponds to the correct animation step
int	*get_monster_sprite(t_monster *m, t_so_long *so_long)
{
	if (m->ai == 4)
	{
		m->ai = 0;
		monster_sprite_pos(m);
	}
	else
		m->ai++;
	return (so_long->ms[m->ap]);
}
