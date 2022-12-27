/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_image2.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 07:29:03 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 07:37:01 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_IMAGE2_H
# define PLAYER_IMAGE2_H

# include "player/player.h"

int	player_attack_sprite(t_player *player);
int	player_walk_sprite(t_player *player);
int	player_hurt_sprite(t_player *player);
int	player_down_sprite(t_player *player);
#endif