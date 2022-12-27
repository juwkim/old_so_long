/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:41:24 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/27 23:22:47 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/hook.h"

int	key_down(int keycode, t_game *game)
{
	set_action(keycode, game);
	return (0);
}

int	key_up(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		destroy(game);
	else
		unset_action(keycode, game);
	return (0);
}

int	destroy(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit(EXIT_SUCCESS);
	return (0);
}
