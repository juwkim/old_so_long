/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:24:20 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 00:51:28 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_BACKGROUND_H
# define DRAW_BACKGROUND_H

# include "main.h"
# include "core/image.h"

enum {
	BLOCK	= 0,
	WALL	= 1
};

void	draw_block(t_game *game, void *block, int x, int y);

#endif