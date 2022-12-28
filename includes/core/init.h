/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:06:11 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 15:26:25 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "config.h"
# include "core/image.h"
# include "core/map.h"
# include "tools/error.h"
# include "monster/monster.h"
# include "player/player.h"

void	init_game(t_game *game);
int		init_map(t_game *game, int argc, char *argv[]);
void	init_image(t_game *game);
int		init_player(t_player *player);
void	init_camera(t_game *game);

#endif