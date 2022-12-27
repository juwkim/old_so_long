/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:41:24 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 04:25:03 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/hook.h"

enum {
	KEY_A		=	0,
	KEY_S		=	1,
	KEY_D		=	2,
	KEY_W		=	13,
	KEY_E		=	14,
	KEY_R		=	15,
	KEY_RETURN	=	36,
	KEY_SPACE	=	49,
	KEY_ESC		=	53,
	KEY_ZERO	=	82,
	KEY_LEFT	=	123,
	KEY_RIGHT	=	124,
	KEY_DOWN	=	125,
	KEY_UP		=	126,
};

int	key_down(int keycode, t_player *p)
{
	if (keycode == KEY_E)
		p->attack = TRUE;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		p->move_horizental = MOVE_LEFT;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		p->move_horizental = MOVE_RIGHT;
	else if (keycode == KEY_UP || keycode == KEY_W || keycode == KEY_SPACE)
		p->move_vertical = MOVE_UP;
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		p->move_vertical = MOVE_DOWN;
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
		p->move_horizental = MOVE_STAY;
	else if (keycode == KEY_UP || keycode == KEY_W || keycode == KEY_SPACE || \
			keycode == KEY_DOWN || keycode == KEY_S)
		p->move_vertical = MOVE_STAY;
	return (0);
}

int	destroy(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit(EXIT_SUCCESS);
	return (0);
}
