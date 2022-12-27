/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:41:32 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 02:58:29 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/init.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, \
					WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	game->map_size.first = -1;
	game->map_size.second = -1;
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
	load_image(game, "./assets/life/life_", BLOCK_NUMBER, BLOCK);
	load_image(game, "./assets/cat/cat_", CAT_NUMBER, CAT);
	load_image(game, "./assets/coin/coin_", COIN_NUMBER, COIN);
	load_image(game, "./assets/gate/gate_", GATE_NUMBER, GATE);
	load_image(game, "./assets/monster/monster_", MONSTER_NUMBER, MONSTER);
	load_image(game, "./assets/other/other_", OTHER_NUMBER, OTHER);
}

int	init_player(t_game *game)
{
	game->player.jump = 0;
	game->player.tick_life = 50;
	game->player.life_number = LIFE_NUMBER;
	game->player.direction = 1;
	return (0);
}

void	init_camera(t_game *game)
{
	game->offset_game.first = 0;
	game->offset_game.second = 0;
	if (game->map_size.first < 15)
		game->offset_game.first = (14 - game->map_size.first) / 2 * BPX;
	if (game->map_size.second < 8)
		game->offset_game.second = (7 - game->map_size.second) / 2 * BPX;
}
