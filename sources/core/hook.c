/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:41:24 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/23 13:41:29 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	keydown_hook(int keycode, t_so_long *so_long)
{
	set_action(keycode, so_long);
	return (0);
}

int	keyup_hook(int keycode, t_so_long *so_long)
{
	if (keycode != 53)
		unset_action(keycode, so_long);
	else
		close_hook(0, so_long);
	return (0);
}

int	close_hook(int keycode, t_so_long *so_long)
{
	if (keycode == 0)
		mlx_destroy_window(so_long->mlx, so_long->window);
	exit(EXIT_SUCCESS);
	return (0);
}
