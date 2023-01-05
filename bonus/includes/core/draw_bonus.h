/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:24:20 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 07:56:08 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_BONUS_H
# define DRAW_BONUS_H

# include "config_bonus.h"
# include "core/image_bonus.h"
# include "core/gate_bonus.h"
# include "core/collectable_bonus.h"

# define STATUS_POS_FIRST 920
# define STATUS_POS_SECOND 10
# define WHITE 0xFFFFFF

enum {
	BLOCK_IDX	= 0,
	WALL_IDX	= 1
};

enum {
	LIFE_ON		= 0,
	LIFE_OFF	= 1,
	PAW			= 2,
	OUTLINE		= 3
};

void	draw_block(t_game *game, void *block, int x, int y);
void	draw_background(t_game *game);
void	draw_status(t_game *game);
void	draw_movement(t_game *game);
void	draw_life(t_game *game);

#endif