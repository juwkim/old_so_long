/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 01:51:05 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 13:20:47 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLECTABLE_H
# define COLLECTABLE_H

# include "main.h"

# define COLLECTABLE_UPDATE_CYCLE 7;

int		*get_collectable_image(t_game *game);
void	collectable_action(t_game *game, int first, int second);
void	collectable_collision(t_game *game);

#endif