/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:41:32 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/23 15:26:14 by juwkim           ###   ########.fr       */
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

// Player initialization
int	init_player(t_game *game)
{
	int		i;
	int		j;

	game->player.jump = 0;
	game->player.tick_life = 50;
	game->player.life_number = NB_LIFE;
	game->player.direction = 1;
	i = 0;
	while (i < game->game_height)
	{
		j = 0;
		while (j < game->game_width)
		{
			if (game->map[i][j] == 'P')
			{
				game->player.position.first = j * BPX;
				game->player.position.second = i * BPX - 1;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	init_camera(t_game *game)
{
	game->game_offset.first = 0;
	game->game_offset.second = 0;
	if (game->game_width < 15)
		game->game_offset.first = (14 - game->game_width) / 2 * BPX + 30;
	if (game->game_height < 8)
		game->game_offset.second = (7 - game->game_height) / 2 * BPX + 35;
}
