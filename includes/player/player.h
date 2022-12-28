/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:14:19 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 14:08:10 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "main.h"
# include "core/map.h"
# include "tools/point.h"

/// @brief 
typedef struct s_player {
	t_point	position;
	t_point	last_position;
	int		move_horizontal;
	int		move_vertical;
	int		jump;
	int		attack;
	int		tick_life;
	int		life_number;
	int		last_image;
}	t_player;

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

void	player_update(t_game *game);
void	player_move_count_update(t_game *game);
void	player_draw(t_game *game);

#endif