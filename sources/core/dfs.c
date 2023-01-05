/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 05:50:55 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 06:28:38 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/dfs.h"

char	**get_visited_array(int x, int y)
{
	int		idx;
	char	**visited;

	visited = malloc(x * sizeof(char *));
	if (visited == NULL)
		exit(EXIT_FAILURE);
	idx = 0;
	while (idx < x)
	{
		visited[idx] = ft_calloc(y, sizeof(char));
		if (visited[idx] == NULL)
			exit(EXIT_FAILURE);
		idx++;
	}
	return (visited);
}

void	free_visited(char **visited, int x)
{
	int	idx;

	idx = 0;
	while (idx < x)
		free(visited[idx++]);
}


int	dfs(char **map, char **visited, int x, int y)
{
	const int	dx[4] = {0, 1, 0, -1};
	const int	dy[4] = {1, 0, -1, 0};
	int			count;
	int			idx;

	count = map[x][y] == CHAR_COLLECTABLE;
	idx = -1;
	while (++idx < 4)
	{
		if (visited[x + dx[idx]][y + dy[idx]] == 1 || \
			map[x + dx[idx]][y + dy[idx]] == CHAR_WALL)
			continue ;
		visited[x + dx[idx]][y + dy[idx]] = 1;
		count += dfs(map, visited, x + dx[idx], y + dy[idx]);
	}
	return (count);
}

int	check_collectable(t_game *game)
{
	int		i;
	int		j;
	int		count;
	char	**visited;

	i = 0;
	j = 0;
	count = 0;
	visited = get_visited_array(game->map_size.second, game->map_size.first);
	ft_printf("%d %d\n", game->map_size.second, game->map_size.first);
	while (++i < game->map_size.second - 1)
	{
		j = 0;
		while (++j < game->map_size.first - 1)
		{
			ft_printf("%d %d\n", i, j);
			if (visited[i][j] == 1 || game->map[i][j] == CHAR_WALL)
				continue ;
			visited[i][j] = 1;
			count += dfs(game->map, visited, i, j);
			if (count == game->count[COLLECTABLE])
				return (1);
		}
	}
	free_visited(visited, game->map_size.second);
	return (count == game->count[COLLECTABLE]);
}
