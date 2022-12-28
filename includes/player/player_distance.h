/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_distance.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 06:24:33 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 21:16:24 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_DISTANCE_H
# define PLAYER_DISTANCE_H

# include "config.h"
# include "core/map.h"

# define SEARCH_STAP 10

int	get_right_dist(t_player *p, char *map[]);
int	get_left_dist(t_player *p, char *map[]);
int	get_down_dist(t_player *p, char *map[]);
int	get_up_dist(t_player *p, char *map[]);

#endif