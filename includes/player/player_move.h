/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 03:06:29 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 15:35:50 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_MOVE_H
# define PLAYER_MOVE_H

# include "config.h"
# include "player/player.h"
# include "player/player_distance.h"

void	player_move_horizontal(t_player *p, char *map[]);
void	player_move_vertical(t_player *p, char *map[]);
void	player_move_up(t_player *p, char *map[]);
void	player_move_down(t_player *p, char *map[]);

#endif