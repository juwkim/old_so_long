/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:23:13 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 14:05:37 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <fcntl.h>
# include "main.h"

enum {
	EMPTY		= '0',
	WALL		= '1',
	PLAYER		= 'P',
	EXIT		= 'E',
	COLLECTABLE = 'C'
};

int	open_map(t_game *game, char *path);
int	read_map(t_game *game, int fd);
int	check_map(t_game *game);
int	check_side(t_game *game);

#endif
