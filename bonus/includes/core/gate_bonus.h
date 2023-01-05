/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gate_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 01:16:10 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 07:56:13 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GATE_BONUS_H
# define GATE_BONUS_H

# include "config_bonus.h"
# include "core/hook_bonus.h"
# include "core/image_bonus.h"
# include "player/player_bonus.h"

# define GATE_UPDATE_CYCLE 7

int		*get_gate_image(t_game *game);
void	gate_collision(t_game *game);

#endif