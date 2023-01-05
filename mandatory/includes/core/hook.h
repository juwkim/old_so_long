/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:16:19 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 15:25:11 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "config.h"
# include "player/player.h"

# define NO_EVENT_MASK 0

typedef struct s_player	t_player;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

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

int	key_down(int keycode, t_player *p);
int	key_up(int keycode, t_game *game);
int	destroy(t_game *game);

#endif