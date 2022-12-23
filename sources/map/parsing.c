/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:43:53 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/23 16:43:20 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/parsing.h"

int	open_map(t_game *game, char *path)
{
	const int	path_len = ft_strlen(path);

	if (path_len <= 4)
		return (0);
	if (ft_strncmp(path + (path_len - 4), ".ber", 4) != 0)
		return (0);
	return (open(path, O_RDONLY));
}

int	read_map(t_game *game, int fd)
{
	char	*line;
	int		idx;

	idx = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (game->width == -1)
			game->width = ft_strlen(line);
		if (ft_strlen(line) != game->width)
			return (0);
		game->map[idx++] = line;
	}
	game->height = idx;
	return (game->width != -1);
}

int	check_map(t_game *game)
{
	int	i;
	int	j;
	int	idx;
	int	elements[5];

	ft_memset(elements, 0, sizeof(elements));
	i = 0;
	while (++i < game->height - 1)
	{
		j = 0;
		while (++j < game->width - 1)
		{
			idx = ft_strin(game->map[i][j], "PCE10");
			if (idx == -1)
				return (0);
			if (game->map[i][j] == 'P')
			{
				game->player.position.first = j * BPX;
				game->player.position.second = i * BPX;
			}
			elements[idx]++;
		}
	}
	game->count[COLLECTABLE] = elements[1];
	return (elements[0] == 1 && elements[1] >= 1 && elements[2] == 1);
}

int	check_side(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			return (0);
	}
	j = -1;
	while (++j < game->width)
	{
		if (game->map[0][j] != '1' || game->map[game->height - 1][j] != '1')
			return (0);
	}
	return (1);
}
