/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:05:28 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 14:04:23 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>

# include "common/ft_printf.h"
# include "common/get_next_line.h"
# include "common/libft.h"
# include "common/mlx.h"

# include "core/hook.h"
# include "core/draw.h"
# include "player/player.h"
# include "tools/point.h"

# define WINDOW_TITLE "game"
# define WINDOW_WIDTH 1366
# define WINDOW_HEIGHT 768
# define LIFE_NUMBER 7

# define MOVE_IDX 0
# define COLLECTABLE_IDX 1

enum e_bool {
	FALSE = 0,
	TRUE = 1
};

/*
BPX : bloc px
MPX : movement px
GPX : ground px
JPX : jump px
HPX : hitbox px
EHPX : extra hitbox
*/

enum e_px {
	MPX = 8,
	GPX = 14,
	HPX = 15,
	DPX = 20,
	EHPX = 25,
	JPX = 40,
	BPX = 100
};

typedef struct s_game {
	void		*mlx;
	void		*window;
	t_point		map_size;
	char		*map[100];
	int			count[2];
	long long	time_stamp;
	t_point		offset_window;
	t_point		offset_game;
	t_list		*monsters;
	t_player	player;
	void		*image[6][54];
}	t_game;

#endif
