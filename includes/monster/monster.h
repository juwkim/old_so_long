/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:59:51 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 03:51:12 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONSTER_H
# define MONSTER_H

# include "config.h"
# include "core/map.h"
# include "player/player.h"
# include "monster/monster_action.h"
# include "monster/monster_image.h"

# define MOSTER_FREQUENCY 10
# define MONSTER_MOVE_COUNT 100
# define NO_HIT_COUNT 10

void	set_monster(t_game *game);
void	new_monster(t_game *game, int second, int first);
void	monster_update(t_game *game);

#endif