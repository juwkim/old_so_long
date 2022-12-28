/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:59:51 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 15:20:21 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONSTER_H
# define MONSTER_H

# include "config.h"

# define MOSTER_FREQUENCY 10

/// @brief Enemy structure
/*
pp : pixel position (pp[0] : x, pp[1] : y)
init_p : initial position (init_p[0] : x, init_p[1] : y)
a : top left		(a[0] : x, a[1] : y)
b : top right		(b[0] : x, b[1] : y)
c : bottom left 	(c[0] : x, c[1] : y)
d : bottom right 	(d[0] : x, d[1] : y)
alive : dead or alive
move : move or not
ta : tick attack
td : tick dead
direction : direction (0 left, 1 right)
la : last annimation
ap : annimation position
ai : annimation interval
mi : move interval
*/
typedef struct s_monster
{
	int	pp[2];
	int	init_p[2];
	int	a[2];
	int	b[2];
	int	c[2];
	int	d[2];
	int	alive;
	int	move;
	int	ta;
	int	td;
	int	direction;
	int	la;
	int	ap;
	int	ai;
	int	mi;
}	t_monster;

#endif