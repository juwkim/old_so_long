/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/12/18 02:33:51 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	draw_block(int x, int y, void *sprite, t_so_long *so_long)
{
	if (x < -BPX || y < -BPX || x > WINDOW_WIDTH || y > WINDOW_HEIGHT)
		return ;
	mlx_put_image_to_window(so_long->mlx, so_long->window,
		sprite, x + so_long->game_offset.first, y + so_long->game_offset.second);
}
