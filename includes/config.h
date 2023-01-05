/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:15:40 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 04:32:14 by juwkim           ###   ########.fr       */
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

# define MAIN_UPDATE_CYCLE	15

# define BLOCK_SIZE			100
# define MARGIN				20
# define HORIZONTAL_SPEED	8
# define VERTICAL_SPEED		15

enum e_bool {
	FALSE = 0,
	TRUE = 1
};

typedef struct s_player {
	t_point	position;
	t_point	last_position;
	int		move_horizontal;
	int		move_vertical;
	int		jump;
	int		life_number;
	int		last_move;
}	t_player;

typedef struct s_game {
	void		*mlx;
	void		*window;
	char		*map[100];
	int			count[2];
	long long	time_stamp;
	t_point		map_size;
	t_point		offset;
	t_list		*monsters;
	t_player	player;
	void		*image[6][54];
}	t_game;

typedef struct s_monster {
	t_point	position;
	t_point	last_position;
	int		move_horizontal;
	int		move;
	int		hited;
	int		image_update;
	int		image_idx;
}	t_monster;

#endif