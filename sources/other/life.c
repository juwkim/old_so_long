/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:43:27 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/23 13:43:31 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	show_life(t_so_long *so_long)
{
	int	i;

	i = 0;
	while (i < so_long->player.life_number)
	{
		mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->os[5], \
		HUD_LM + 167 + (i * 35), 10);
		i++;
	}
	while (i < NB_LIFE)
	{
		mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->os[6], \
		HUD_LM + 167 + (i * 35), 10);
		i++;
	}
}

static void	show_movement(t_so_long *so_long)
{
	char	*nb_movement;

	mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->os[4], \
	HUD_LM + 20, 17);
	nb_movement = ft_itoa(so_long->move_count);
	mlx_string_put(so_long->mlx, so_long->window, \
		HUD_LM + 60, 35, 0xFFFFFF, nb_movement);
	free(nb_movement);
}

void	show_hud(t_so_long *so_long)
{
	mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->os[3], \
	HUD_LM + 10, 10);
	show_movement(so_long);
	show_life(so_long);
}