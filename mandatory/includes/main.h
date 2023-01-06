/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:05:28 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/06 11:19:09 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>

# include "core/draw.h"
# include "core/hook.h"
# include "core/init.h"
# include "player/player.h"
# include "config.h"

int	main(int argc, char *argv[]);
int	game_loop(t_game *game);

#endif
