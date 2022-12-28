/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:41:24 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 20:39:45 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/hook.h"

int	key_down(int keycode, t_player *p)
{
	if (keycode == KEY_E)
		p->attack = TRUE;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		p->move_horizontal = MOVE_LEFT;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		p->move_horizontal = MOVE_RIGHT;
	else if (keycode == KEY_UP || keycode == KEY_W || keycode == KEY_SPACE)
	{
		if (p->move_vertical == MOVE_STAY)
			p->move_vertical = MOVE_UP;
	}
	else if (keycode == KEY_DOWN || keycode == KEY_S)
	{
		if (p->move_vertical == MOVE_STAY)
			p->move_vertical = MOVE_DOWN;
	}
	return (0);
}

int	key_up(int keycode, t_game *game)
{
	t_player	*p;

	p = &game->player;
	if (keycode == KEY_ESC)
		destroy(game);
	else if (keycode == KEY_E)
		p->attack = FALSE;
	else if (keycode == KEY_A || keycode == KEY_LEFT || \
			keycode == KEY_D || keycode == KEY_RIGHT)
		p->move_horizontal = MOVE_STAY;
	return (0);
}

int	destroy(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit(EXIT_SUCCESS);
	return (0);
}
