/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:14:19 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 01:12:46 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "main.h"

/// @brief Structure for the player
/*
pp : pixel position (pp[0] : x, pp[1] : y)
lpp : last pixel position (lpp[0] : x, lpp[1] : y)
a : top left		(a[0] : x, a[1] : y)
b : top right		(b[0] : x, b[1] : y)
c : bottom left 	(c[0] : x, c[1] : y)
d : bottom right 	(d[0] : x, d[1] : y)
js : jump state
ac : actions code
di : diagonal (1 : left, 2 : right)
tl : tick life
nl : life number
direction : (0 left, 1 right)
*/

typedef struct s_player
{
	t_point	position;
	t_point	lpp;
	t_point	top_left;
	t_point	top_right;
	t_point	btm_left;
	t_point	btm_right;
	int		jump;
	int		action_code[3];
	int		di;
	int		tick_life;
	int		life_number;
	int		direction;
}	t_player;

#endif