/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:05:28 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 11:27:23 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_BONUS_H
# define MAIN_BONUS_H

# include <stdlib.h>

# include "core/draw_bonus.h"
# include "core/hook_bonus.h"
# include "core/init_bonus.h"
# include "player/player_bonus.h"
# include "config_bonus.h"

int	main(int argc, char *argv[]);
int	game_loop(t_game *game);

#endif
