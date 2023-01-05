/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 01:51:05 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 07:54:29 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLECTABLE_BONUS_H
# define COLLECTABLE_BONUS_H

# include "config_bonus.h"
# include "core/map_bonus.h"
# include "core/image_bonus.h"

# define COLLECTABLE_UPDATE_CYCLE 30;

int		*get_collectable_image(t_game *game);
void	collectable_collision(t_game *game);

#endif