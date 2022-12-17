/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/12/15 15:38:01 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static char	*path_sprite(char *sprite_name, int nb)
{
	char	*nbr;
	char	*str1;
	char	*str2;

	nbr = ft_itoa(nb);
	str1 = ft_strjoin("./assets/", sprite_name);
	str2 = ft_strjoin(str1, "/");
	free(str1);
	str1 = ft_strjoin(str2, sprite_name);
	free(str2);
	str2 = ft_strjoin(str1, "_");
	free(str1);
	str1 = ft_strjoin(str2, nbr);
	free(str2);
	str2 = ft_strjoin(str1, ".png");
	free(str1);
	free(nbr);
	return (str2);
}

static void	load_sprite_type(int i, char *p, int sprite_type,
t_so_long *so_long)
{
	int		d;

	d = BPX;
	if (sprite_type == 1)
		so_long->ps[i] = mlx_png_file_to_image(so_long->mlx, p, &d, &d);
	else if (sprite_type == 2)
		so_long->ms[i] = mlx_png_file_to_image(so_long->mlx, p, &d, &d);
	else if (sprite_type == 3)
		so_long->gs[i] = mlx_png_file_to_image(so_long->mlx, p, &d, &d);
	else if (sprite_type == 4)
		so_long->cs[i] = mlx_png_file_to_image(so_long->mlx, p, &d, &d);
	else if (sprite_type == 5)
		so_long->os[i] = mlx_png_file_to_image(so_long->mlx, p, &d, &d);
}

static void	load_sprite(char *sprite_name, int nb_sprite, int sprite_type, \
t_so_long *so_long)
{
	int		i;
	char	*p;
	int		fd;

	i = 0;
	while (i < nb_sprite)
	{
		p = path_sprite(sprite_name, i);
		fd = open(p, O_RDONLY);
		if (fd < 0)
			error(3);
		close(fd);
		load_sprite_type(i, p, sprite_type, so_long);
		free(p);
		++i;
	}
}

// All sprites initialization
void	init_sprites(t_so_long *so_long)
{
	load_sprite("other", 7, 5, so_long);
	load_sprite("cat", 54, 1, so_long);
	load_sprite("monster", 22, 2, so_long);
	load_sprite("gate", 4, 3, so_long);
	load_sprite("coin", 5, 4, so_long);
}
