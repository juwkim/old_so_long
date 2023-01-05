/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:41:32 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 08:02:57 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/init_bonus.h"

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
	game->offset.first = 0;
	game->offset.second = 0;
	game->monsters = NULL;
}

int	init_map(t_game *game, int argc, char *argv[])
{
	int	fd;

	if (argc != 2)
		error(0);
	fd = open_map(argv[1]);
	if (fd <= 0)
		error(1);
	if (!read_map(game, fd) || !check_map(game) || \
		!check_side(game) || !check_collectable(game))
		error(2);
	return (1);
}

void	init_image(t_game *game)
{
	load_image(game, "./assets/block/block_", BLOCK_NUMBER, BLOCK);
	load_image(game, "./assets/cat/cat_", CAT_NUMBER, CAT);
	load_image(game, "./assets/coin/coin_", COIN_NUMBER, COIN);
	load_image(game, "./assets/gate/gate_", GATE_NUMBER, GATE);
	load_image(game, "./assets/monster/monster_", MONSTER_NUMBER, MONSTER);
	load_image(game, "./assets/other/other_", OTHER_NUMBER, OTHER);
}

int	init_player(t_player *player)
{
	player->jump = 0;
	player->life_number = LIFE_NUMBER;
	player->move_horizontal = MOVE_STAY;
	player->move_vertical = MOVE_STAY;
	player->last_move = MOVE_RIGHT;
	return (0);
}
