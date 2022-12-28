/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:41:37 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 21:36:14 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	init_game(&game);
	init_map(&game, argc, argv);
	init_image(&game);
	init_player(&game.player);
	init_camera(&game);
	set_monster(&game);
	mlx_hook(game.window, ON_KEYDOWN, NO_EVENT_MASK, key_down, &game.player);
	mlx_hook(game.window, ON_KEYUP, NO_EVENT_MASK, key_up, &game);
	mlx_hook(game.window, ON_DESTROY, NO_EVENT_MASK, destroy, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	exit(EXIT_SUCCESS);
}

int	game_loop(t_game *game)
{
	const long long	now = time_stamp();

	if (now - game->time_stamp > MAIN_UPDATE_CYCLE)
	{
		game->time_stamp = now;
		gate_collision(game);
		collectable_collision(game);
		draw_background(game);
		draw_status(game);
		player_update(game);
	}
	return (1);
}
