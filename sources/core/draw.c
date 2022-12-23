/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:40:59 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/23 17:13:36 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/draw.h"

void	draw_block(t_game *game, int x, int y, void *block)
{
	if (x < -BPX || y < -BPX || x > WINDOW_WIDTH || y > WINDOW_HEIGHT)
		return ;
	mlx_put_image_to_window(game->mlx, game->window, block, x, y);
}
