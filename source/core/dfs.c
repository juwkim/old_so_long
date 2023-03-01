/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 05:50:55 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 23:20:16 by juwkim           ###   ########.fr       */
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
	free(visited);
}

int	dfs(char **map, char **visited, int x, int y)
{
	const int	dx[4] = {0, 1, 0, -1};
	const int	dy[4] = {1, 0, -1, 0};
	int			count;
	int			idx;

	count = ((map[x][y] == CHAR_COLLECTABLE) || (map[x][y] == CHAR_EXIT));
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
	int				count;
	char			**visited;
	const int		i = game->player.position.second / BLOCK_SIZE;
	const int		j = game->player.position.first / BLOCK_SIZE;

	visited = get_visited_array(game->map_size.second, game->map_size.first);
	visited[i][j] = 1;
	count = dfs(game->map, visited, i, j);
	free_visited(visited, game->map_size.second);
	return (count == game->count[COLLECTABLE] + 1);
}
