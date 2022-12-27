/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:41:44 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/23 16:47:37 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/image.h"

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
		ft_memcpy(path + name_len, idx_str, ft_strlen(idx_str));
		ft_memcpy(path + name_len + ft_strlen(idx_str), ".png", 4);
		game->image[type][idx] = mlx_png_file_to_image(game->mlx, \
									path, &img_size, &img_size);
		free(idx_str);
	}
}