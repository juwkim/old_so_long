/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:41:44 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/23 16:15:21 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/main.h"

void	init_image(t_game *game)
{
	load_sprite(game, "./assets/cat/cat_", CAT_IMAGE_NUMBER, 0);
	load_sprite(game, "./assets/coin/coin_", COIN_IMAGE_NUMBER, 1);
	load_sprite(game, "./assets/gate/gate_", GATE_IMAGE_NUMBER, 2);
	load_sprite(game, "./assets/life/life_", LIFE_IMAGE_NUMBER, 3);
	load_sprite(game, "./assets/monster/monster_", MONSTER_IMAGE_NUMBER, 4);
	load_sprite(game, "./assets/other/other_", OTHER_IMAGE_NUMBER, 5);
}

void	load_sprite(t_game *game, char *name, int sprite_number, int type)
{
	int			idx;
	const int	img_size = BPX;
	char		*idx_str;
	char		path[100];
	const int	name_len = ft_strlen(name);

	ft_memcpy(path, name, name_len);
	idx = -1;
	while (++idx < sprite_number)
	{
		idx_str = ft_itoa(idx);
		make_path(idx);
		game->image[type][idx] = mlx_png_file_to_image(game->mlx, \
									path, &img_size, &img_size);
	}
}

static char	*path_sprite(char *sprite_name, int nb)
{
	char	*nbr;
	char	*str1;
	char	*str2;

	nbr = ft_itoa(nb);
	str1 = ft_strjoin(str2, nbr);
	free(str2);
	str2 = ft_strjoin(str1, ".png");
	free(str1);
	free(nbr);
	return (str2);
}


void	load_sprite(t_game *game, char *name, int sprite_number, int type)
{
	int			fd;
	int			idx;
	const int	img_size = BPX;
	char		*idx_str;
	char		path[100];
	const int	name_len = ft_strlen(name);

	ft_memcpy(path, name, name_len);
	idx = -1;
	while (++idx < sprite_number)
	{
		idx_str = ft_itoa(idx);

		fd = open(path, O_RDONLY);
		if (fd < 0)
			error(3);
		close(fd);
		free(idx_str);
		game[type][idx] = mlx_png_file_to_image(game->mlx, p, &d, &d);
		load_sprite_type(i, p, sprite_type, game);
	}
}