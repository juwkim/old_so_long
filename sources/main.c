/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:41:37 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/27 23:28:28 by juwkim           ###   ########.fr       */
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
	mlx_hook(game.window, ON_KEYDOWN, NO_EVENT_MASK, key_down, &game);
	mlx_hook(game.window, ON_KEYUP, NO_EVENT_MASK, key_up, &game);
	mlx_hook(game.window, ON_DESTROY, NO_EVENT_MASK, destroy, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	exit(EXIT_SUCCESS);
}

static int	game_loop(t_game *game)
{
	const long long	now = millitimestamp();
	long long		diff_millisecs;

	diff_millisecs = now - game->time_stamp;
	if (diff_millisecs > 15)
	{
		fps(game);
		mlx_clear_window(game->mlx, game->window);
		player_position(game);
		draw_background(game);
		wall(game);
		item(game);
		gate(game);
		monster(game);
		player(game);
		show_hud(game);
	}
	return (1);
}
