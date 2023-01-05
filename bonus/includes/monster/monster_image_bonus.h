/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_image_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:01:31 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 07:58:00 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONSTER_IMAGE_BONUS_H
# define MONSTER_IMAGE_BONUS_H

# include "monster/monster_bonus.h"

# define UPDATE_CYCLE 5

int	get_monster_image_idx(t_monster *monster);
int	*get_monster_image(t_game *game, t_monster *monster);

#endif