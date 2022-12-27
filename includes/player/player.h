/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:14:19 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 02:46:32 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "main.h"

/// @brief Structure for the player
/*
lpp : last pixel position (lpp[0] : x, lpp[1] : y)
ac : actions code
di : diagonal (1 : left, 2 : right)
tl : tick life
*/

enum e_direction {
	LEFT = 0,
	RIGHT = 1
};

typedef struct s_player
{
	t_point	position;
	t_point	lpp;
	int		jump;
	int		action_code[3];
	int		diagonal;
	int		tick_life;
	int		life_number;
	int		direction;
}	t_player;

#endif