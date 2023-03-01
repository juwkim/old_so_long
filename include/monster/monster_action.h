/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_action.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 01:07:45 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 08:03:26 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONSTER_ACTION_H
# define MONSTER_ACTION_H

# include "monster/monster.h"

# define COLLISION_HIT 20

void	monster_move(t_monster *monster, char *map[]);
void	monster_collision(t_game *game, t_monster *monster);

#endif // MONSTER_ACTION_H
