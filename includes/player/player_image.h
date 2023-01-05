/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_image.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 06:54:55 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 03:26:51 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_IMAGE_H
# define PLAYER_IMAGE_H

# include "config.h"
# include "core/image.h"
# include "player/player_distance.h"
# include "player/player.h"

# define UPDATE_CYCLE 5

int	*get_player_image(t_game *game, t_player *player);
int	get_jump_image(t_player *player);
int	get_down_image(t_player *player);
int	get_stay_image(t_player *player);
int	get_walk_image(t_player *player);

#endif