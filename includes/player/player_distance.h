/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_distance.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 06:24:33 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 06:25:48 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_DISTANCE_H
# define PLAYER_DISTANCE_H

# include "player/player.h"

int	get_right_dist(t_player *p, char *map[]);
int	get_left_dist(t_player *p, char *map[]);
int	get_down_dist(t_player *p, char *map[]);
int	get_up_dist(t_player *p, char *map[]);

#endif