/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:41:32 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/23 16:47:45 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/init.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, \
					WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	game->width = -1;
	game->height = -1;
	game->time_stamp = 0;
	game->count[MOVE] = 0;
	game->count[COLLECTABLE] = 0;
	game->offset_window.first = 0;
	game->offset_window.second = 0;
	game->monsters = NULL;
}

int	init_map(t_game *game, int argc, char *argv[])
{
	int	fd;

	if (argc != 2)
		error(0);
	fd = open_map(argv[1], game);
	if (fd <= 0)
		error(1);
	if (!read_map(game, fd) || !check_map(game) || !check_wall(game))
		error(2);
	return (1);
}

void	init_image(t_game *game)
{
	load_sprite(game, "./assets/cat/cat_", CAT_IMAGE_NUMBER, 0);
	load_sprite(game, "./assets/coin/coin_", COIN_IMAGE_NUMBER, 1);
	load_sprite(game, "./assets/gate/gate_", GATE_IMAGE_NUMBER, 2);
	load_sprite(game, "./assets/life/life_", LIFE_IMAGE_NUMBER, 3);
	load_sprite(game, "./assets/monster/monster_", MONSTER_IMAGE_NUMBER, 4);
	load_sprite(game, "./assets/other/other_", OTHER_IMAGE_NUMBER, 5);
}

int	init_player(t_game *game)
{
	game->player.jump = 0;
	game->player.tick_life = 50;
	game->player.life_number = NB_LIFE;
	game->player.direction = 1;
	return (0);
}

void	init_camera(t_game *game)
{
	game->offset_game.first = 0;
	game->offset_game.second = 0;
	if (game->width < 15)
		game->offset_game.first = (14 - game->width) / 2 * BPX;
	if (game->height < 8)
		game->offset_game.second = (7 - game->height) / 2 * BPX;
}
