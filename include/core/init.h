/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:06:11 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 07:56:29 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "config.h"
# include "core/image.h"
# include "core/map.h"
# include "core/dfs.h"
# include "utils/error.h"
# include "monster/monster.h"
# include "player/player.h"

void	init_game(t_game *game);
int		init_map(t_game *game, int argc, char *argv[]);
void	init_image(t_game *game);
int		init_player(t_player *player);

#endif // INIT_H
