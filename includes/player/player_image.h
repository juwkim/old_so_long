/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_image.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 06:54:55 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 13:19:24 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_IMAGE_H
# define PLAYER_IMAGE_H

# include "player/player.h"

# define UPDATE_CYCLE 5

int	*get_player_image(t_game *game);
int	player_sprite_pos(t_game *game, int attack_progress, int hurt_progress);
int	player_jump_image(t_player *player);
int	player_failling_sprite(t_player *player);
int	player_stay_sprite(t_player *player);

#endif