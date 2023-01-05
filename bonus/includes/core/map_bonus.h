/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:23:13 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 07:57:04 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_BONUS_H
# define MAP_BONUS_H

# include <fcntl.h>
# include "config_bonus.h"

enum {
	CHAR_EMPTY			= '0',
	CHAR_WALL			= '1',
	CHAR_PLAYER			= 'P',
	CHAR_EXIT			= 'E',
	CHAR_COLLECTABLE	= 'C'
};

int	open_map(char *path);
int	read_map(t_game *game, int fd);
int	check_map(t_game *game);
int	check_side(t_game *game);

#endif
