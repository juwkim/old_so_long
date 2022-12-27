/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:43:53 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 05:44:11 by juwkim           ###   ########.fr       */
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
		if (game->map_size.first == -1)
			game->map_size.first = ft_strlen(line);
		if (ft_strlen(line) != game->map_size.first)
			return (0);
		game->map[idx++] = line;
	}
	game->map_size.second = idx;
	return (game->map_size.first != -1);
}

int	check_map(t_game *game)
{
	int	i;
	int	j;
	int	idx;
	int	elements[5];

	ft_memset(elements, 0, sizeof(elements));
	i = 0;
	while (++i < game->map_size.second - 1)
	{
		j = 0;
		while (++j < game->map_size.first - 1)
		{
			idx = ft_strfind(game->map[i][j], "PCE10");
			if (idx == -1)
				return (0);
			if (game->map[i][j] == PLAYER)
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
	while (++i < game->map_size.first)
	{
		if (game->map[i][0] != WALL || \
		game->map[i][game->map_size.second - 1] != WALL)
			return (0);
	}
	j = -1;
	while (++j < game->map_size.second)
	{
		if (game->map[0][j] != WALL || \
		game->map[game->map_size.first - 1][j] != WALL)
			return (0);
	}
	return (1);
}
