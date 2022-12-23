/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:06:11 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/23 17:18:32 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "main.h"

void	init_game(t_game *game);
int		init_map(t_game *game, int argc, char *argv[]);
void	init_image(t_game *game);
int		init_player(t_game *game);
void	init_camera(t_game *game);

#endif