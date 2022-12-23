/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/12/23 11:56:30 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_block(int x, int y, void *sprite, t_so_long *so_long)
{
	mlx_put_image_to_window(so_long->mlx, so_long->window, sprite, x, y);
}
