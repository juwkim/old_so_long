/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 01:51:05 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 21:30:13 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLECTABLE_H
# define COLLECTABLE_H

# include "config.h"
# include "core/map.h"
# include "core/image.h"

# define COLLECTABLE_UPDATE_CYCLE 30;

int		*get_collectable_image(t_game *game);
void	collectable_collision(t_game *game);

#endif