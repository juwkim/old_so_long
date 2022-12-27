/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:05:28 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 02:57:21 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <fcntl.h>
# include <stdlib.h>

# include "common/ft_printf.h"
# include "common/get_next_line.h"
# include "common/libft.h"
# include "common/mlx.h"

# include "core/hook.h"
# include "core/draw.h"
# include "tools/point.h"
# include "player/player.h"

# define WINDOW_TITLE "game"
# define WINDOW_WIDTH 1366
# define WINDOW_HEIGHT 768
# define LIFE_NUMBER 7

# define MOVE 0
# define COLLECTABLE 1

/*
BPX : bloc px
MPX : movement px
GPX : ground px
JPX : jump px
HPX : hitbox px
EHPX : extra hitbox
*/

# define BPX 100
# define MPX 8
# define GPX 14
# define DPX 20
# define JPX 40
# define HPX 15
# define EHPX 25

/// @brief Struct that contains all the data of the game
/*
mlx : mlx pointer
window : window pointer
gw : game width
gh : game height
map_fd : map file descriptor
lst_map : linked list that contains datas map
map : map (2D array)
lm : last millitimestamp
fps : frame per second
po : player offset
go : global offset
nc : number collectable
nm : number movements
player : player struct
monster : monster struct
*/

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
