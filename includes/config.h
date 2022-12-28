/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:15:40 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 17:31:21 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "common/ft_printf.h"
# include "common/get_next_line.h"
# include "common/libft.h"
# include "common/mlx.h"

# include "tools/point.h"

# define WINDOW_TITLE "game"
# define WINDOW_WIDTH 1366
# define WINDOW_HEIGHT 768
# define LIFE_NUMBER 7

# define MOVE 0
# define COLLECTABLE 1

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

typedef struct s_player {
	t_point	position;
	t_point	last_position;
	int		move_horizontal;
	int		move_vertical;
	int		jump;
	int		attack;
	int		tick_life;
	int		life_number;
	int		last_image;
}	t_player;

typedef struct s_game {
	void		*mlx;
	void		*window;
	char		*map[100];
	int			count[2];
	long long	time_stamp;
	t_point		map_size;
	t_point		offset_window;
	t_point		offset_game;
	t_list		*monsters;
	t_player	player;
	void		*image[6][54];
}	t_game;

#endif