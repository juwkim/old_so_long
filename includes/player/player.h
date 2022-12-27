/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:14:19 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 07:17:28 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "main.h"
# include "map/parsing.h"

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

enum e_bool {
	FALSE = 0,
	TRUE = 1
};

enum e_move {
	MOVE_STAY,
	MOVE_LEFT,
	MOVE_RIGHT,
	MOVE_UP,
	MOVE_DOWN
};

typedef struct s_player
{
	t_point	position;
	t_point	last_position;
	int		move_horizontal;
	int		move_vertical;
	int		jump;
	int		attack;
	int		diagonal;
	int		tick_life;
	int		life_number;
	int		last_image;
	int		jump;
}	t_player;

void	player_update(t_game *game);
void	player_move_count_update(t_game *game);
void	player_draw(t_game *game);

#endif