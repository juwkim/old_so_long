/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:05:28 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/23 17:10:04 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <sys/time.h>
# include <fcntl.h>
# include <stdlib.h>

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"

# define WINDOW_TITLE "game"
# define WINDOW_WIDTH 1366
# define WINDOW_HEIGHT 768
# define NB_LIFE 7
# define HUD_LM 920

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

/// @brief Structure for the player
/*
pp : pixel position (pp[0] : x, pp[1] : y)
lpp : last pixel position (lpp[0] : x, lpp[1] : y)
a : top left		(a[0] : x, a[1] : y)
b : top right		(b[0] : x, b[1] : y)
c : bottom left 	(c[0] : x, c[1] : y)
d : bottom right 	(d[0] : x, d[1] : y)
js : jump state
ac : actions code
di : diagonal (1 : left, 2 : right)
tl : tick life
nl : life number
direction : (0 left, 1 right)
*/

typedef struct s_point
{
	int	first;
	int	second;
}	t_point;

typedef struct s_player
{
	t_point	position;
	t_point	lpp;
	int		a[2];
	int		b[2];
	int		c[2];
	int		d[2];
	int		jump;
	int		action_code[3];
	int		di;
	int		tick_life;
	int		life_number;
	int		direction;
}	t_player;

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

# define MOVE 0
# define COLLECTABLE 1

# define CAT_IMAGE_NUMBER 54
# define COIN_IMAGE_NUMBER 5
# define GATE_IMAGE_NUMBER 5
# define LIFE_IMAGE_NUMBER 2
# define MONSTER_IMAGE_NUMBER 22
# define OTHER_IMAGE_NUMBER 5

typedef struct s_game {
	void		*mlx;
	void		*window;
	int			width;
	int			height;
	char		*map[100];
	int			count[2];
	long long	time_stamp;
	t_point		offset_window;
	t_point		offset_game;
	t_list		*monsters;
	t_player	player;
	void		*image[6][54];
}	t_game;

// core
void		init_game(t_game *game);
void		init_sprites(t_game *game);
int			init_player(t_game *game);
void		init_camera(t_game *game);

// tools and debug
int			is_bonus(void);
long long	millitimestamp(void);
void		fps(t_game *game);
void		show_fps(t_game *game);
void		show_action(t_game *game);
void		show_debug(t_game *game);
int			limit_args(int argc, char *argv[]);
int			open_map(char *relative_path, t_game *game);
int			fill_lst(t_game *game);
int			convert_lst(t_game *game);
int			size_check(t_game *game);
int			allowed_char(t_game *game);
int			required_char(t_game *game);
int			sides_is_wall(t_game *game);
void		show_debug_map(t_game *game);
void		show_debug_map2(t_game *game);
void		sl_error(int error_n, t_game *game);
void		draw_block(int x, int y, void *sprite, t_game *game);

// actions & hooks
void		set_action(int keycode, t_game *game);
void		unset_action(int keycode, t_game *game);
int			keydown_hook(int keycode, t_game *game);
int			keyup_hook(int keycode, t_game *game);
int			close_hook(int keycode, t_game *game);

// wall & background
void		wall(t_game *game);
void		background(t_game *game);

// player
void		player(t_game *game);
int			get_plwc(t_game *game);
int			get_prwc(t_game *game);
int			get_pgwc(t_game *game);
int			get_pdwc(t_game *game);
int			get_pjwc(t_game *game);
void		player_position(t_game *game);
void		player_move_y(t_game *game);
void		player_move_z(t_game *game);
void		player_move_d(t_game *game);
void		player_jump(t_game *game);
void		player_gravity(t_game *game);
void		player_count_movement(t_game *game);
void		player_draw(t_game *game);
int			*get_player_sprite(t_game *game);
int			player_stay_sprite(int *last_anim, t_game *game);
int			player_failling_sprite(int *last_anim, t_game *game);
int			player_down_sprite(int *last_anim, t_game *game);
int			player_hurt_sprite(int *last_anim, t_game *game);
int			player_walk_sprite(int *last_anim, t_game *game);
int			player_attack_sprite(int *last_anim, t_game *game);
int			player_jumb_sprite(int *last_anim, t_game *game);

// item
void		item(t_game *game);

// monster
void		monster(t_game *game);
int			get_mrwc(t_monster *monster, t_game *game);
int			get_mlwc(t_monster *monster, t_game *game);
void		analyse_monster(t_game *game);
void		monster_position(t_monster *monster);
void		monster_interaction(t_game *game);
void		monster_move(t_game *game);
int			*get_monster_sprite(t_monster *m, t_game *game);

// gate
void		gate(t_game *game);

// hud
void		show_hud(t_game *game);

#endif