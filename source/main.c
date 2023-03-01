/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:41:37 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 23:21:21 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/draw.h"
#include "core/hook.h"
#include "core/init.h"
#include "player/player.h"
#include "config.h"

static int	game_loop(t_game *game);

int	main(int argc, char *argv[])
{
	t_game	game;

	init_game(&game);
	init_map(&game, argc, argv);
	init_image(&game);
	init_player(&game.player);
	set_monster(&game);
	mlx_hook(game.window, ON_KEYDOWN, NO_EVENT_MASK, key_down, &game.player);
	mlx_hook(game.window, ON_KEYUP, NO_EVENT_MASK, key_up, &game);
	mlx_hook(game.window, ON_DESTROY, NO_EVENT_MASK, destroy, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	exit(EXIT_SUCCESS);
}

static int	game_loop(t_game *game)
{
	static int		update;

	update = (update + 1) % MAIN_UPDATE_CYCLE;
	if (update == 0)
	{
		gate_collision(game);
		collectable_collision(game);
		draw_background(game);
		draw_status(game);
		player_update(game);
		monster_update(game);
		if (game->player.life_number <= 0)
			exit(0);
	}
	return (1);
}
