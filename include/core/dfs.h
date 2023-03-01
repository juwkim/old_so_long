/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 05:51:39 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 07:54:39 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DFS_H
# define DFS_H

# include "config.h"
# include "core/map.h"

char	**get_visited_array(int x, int y);
void	free_visited(char **visited, int x);
int		dfs(char **map, char **visited, int x, int y);
int		check_collectable(t_game *game);

#endif // DFS_H
