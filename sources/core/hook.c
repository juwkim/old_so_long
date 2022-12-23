/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:41:24 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/23 17:26:00 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/hook.h"

int	keydown_hook(int keycode, t_game *game)
{
	set_action(keycode, game);
	return (0);
}

int	keyup_hook(int keycode, t_game *game)
{
	if (keycode != 53)
		unset_action(keycode, game);
	else
		close_hook(0, game);
	return (0);
}

int	close_hook(int keycode, t_game *game)
{
	if (keycode == 0)
		mlx_destroy_window(game->mlx, game->window);
	exit(EXIT_SUCCESS);
	return (0);
}
