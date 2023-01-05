/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:14:19 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 08:03:14 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_BONUS_H
# define PLAYER_BONUS_H

# include "config_bonus.h"
# include "core/map_bonus.h"
# include "player/player_image_bonus.h"
# include "player/player_move_bonus.h"

enum e_direction {
	LEFT = 0,
	RIGHT = 1
};

enum e_move {
	MOVE_LEFT,
	MOVE_RIGHT,
	MOVE_UP,
	MOVE_DOWN,
	MOVE_STAY
};

void	player_update(t_game *game);
void	player_move_count_update(t_game *game);
void	player_draw(t_game *game, t_player *p);

#endif