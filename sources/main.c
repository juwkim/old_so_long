/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:41:37 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/23 17:49:31 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	init_game(&game);
	init_map(&game, argc, argv);
	init_image(&game);
	init_player(&game);
	init_camera(&game);
	create_monster(&game);
	mlx_hook(game.window, 2, 0, keydown_hook, &game);
	mlx_hook(game.window, 3, 0, keyup_hook, &game);
	mlx_hook(game.window, 17, 1L << 17, close_hook, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	exit(EXIT_SUCCESS);
}

// General loop of the game which will be executed at best every 15ms
static int	game_loop(t_game *game)
{
	const long long	now = millitimestamp();
	long long	diff_millisecs;

	diff_millisecs = now - game->time_stamp;
	if (diff_millisecs > 15)
	{
		fps(game);
		mlx_clear_window(game->mlx, game->window);
		player_position(game);
		background(game);
		wall(game);
		item(game);
		gate(game);
		monster(game);
		player(game);
		show_hud(game);
	}
	return (1);
}
