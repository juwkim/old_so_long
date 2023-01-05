/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:59:51 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 08:18:53 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONSTER_BONUS_H
# define MONSTER_BONUS_H

# include "config_bonus.h"
# include "core/map_bonus.h"
# include "player/player_bonus.h"
# include "monster/monster_action_bonus.h"
# include "monster/monster_image_bonus.h"

# define MOSTER_FREQUENCY 10
# define MONSTER_MOVE_COUNT 100
# define NO_HIT_COUNT 30

void	set_monster(t_game *game);
void	new_monster(t_game *game, int second, int first);
void	monster_update(t_game *game);

#endif