/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:06:11 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 07:56:29 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_BONUS_H
# define INIT_BONUS_H

# include "config_bonus.h"
# include "core/image_bonus.h"
# include "core/map_bonus.h"
# include "core/dfs_bonus.h"
# include "tools/error_bonus.h"
# include "monster/monster_bonus.h"
# include "player/player_bonus.h"

void	init_game(t_game *game);
int		init_map(t_game *game, int argc, char *argv[]);
void	init_image(t_game *game);
int		init_player(t_player *player);

#endif