/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/12/16 17:42:48 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Initialization of the t_so_long structure
void	init_so_long(t_so_long *so_long)
{
	so_long->mlx = mlx_init();
	so_long->window = mlx_new_window(so_long->mlx, \
									WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	so_long->game_width = -1;
	so_long->game_height = -1;
	so_long->lm = 0;
	so_long->window_offset.first = 0;
	so_long->window_offset.second = 0;
	so_long->move_count = 0;
	so_long->lst_map = NULL;
	so_long->monsters = NULL;
}

int	init_map(int argc, char *argv[], t_so_long *so_long)
{
	if (argc != 2)
		error(0);
	if (open_map(argv[1], so_long) == 0)
		error(1);
	if (!fill_lst(so_long) || \
		!convert_lst(so_long) || \
		!size_check(so_long) || \
		!allowed_char(so_long) || \
		!sides_is_wall(so_long) || \
		!required_char(so_long))
		error(2);
	return (1);
}

// Player initialization
int	init_player(t_so_long *so_long)
{
	int		i;
	int		j;

	so_long->player.jump = 0;
	so_long->player.tick_life = 50;
	so_long->player.life_number = NB_LIFE;
	so_long->player.direction = 1;
	i = 0;
	while (i < so_long->game_height)
	{
		j = 0;
		while (j < so_long->game_width)
		{
			if (so_long->map[i][j] == 'P')
			{
				so_long->player.position.first = j * BPX;
				so_long->player.position.second = i * BPX - 1;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	init_camera(t_so_long *so_long)
{
	so_long->game_offset.first = 0;
	so_long->game_offset.second = 0;
	if (so_long->game_width < 15)
		so_long->game_offset.first = (14 - so_long->game_width) / 2 * BPX + 30;
	if (so_long->game_height < 8)
		so_long->game_offset.second = (7 - so_long->game_height) / 2 * BPX + 35;
}
