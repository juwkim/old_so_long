/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:41:37 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 11:20:52 by juwkim           ###   ########.fr       */
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
	mlx_hook(game.window, ON_KEYDOWN, NO_EVENT_MASK, key_down, &game.player);
	mlx_hook(game.window, ON_KEYUP, NO_EVENT_MASK, key_up, &game);
	mlx_hook(game.window, ON_DESTROY, NO_EVENT_MASK, destroy, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	exit(EXIT_SUCCESS);
}

int	game_loop(t_game *game)
{
	static int		last_move;
	static int		update;

	update = (update + 1) % MAIN_UPDATE_CYCLE;
	if (update == 0)
	{
		gate_collision(game);
		collectable_collision(game);
		draw_background(game);
		if (last_move != game->count[MOVE])
		{
			ft_printf("moved: %d\n", game->count[MOVE]);
			last_move = game->count[MOVE];
		}
		player_update(game);
	}
	return (1);
}
