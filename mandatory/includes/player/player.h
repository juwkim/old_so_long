/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:14:19 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 05:01:48 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "config.h"
# include "core/map.h"
# include "player/player_image.h"
# include "player/player_move.h"

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