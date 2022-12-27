/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:35:09 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/27 23:39:22 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "main.h"

enum {
	CAT_NUMBER = 54,
	COIN_NUMBER = 5,
	GATE_NUMBER = 5,
	LIFE_NUMBER = 2,
	MONSTER_NUMBER = 22,
	OTHER_NUMBER = 5
};

enum {
	CAT = 0,
	COIN = 1,
	GATE = 2,
	LIFE = 3,
	MONSTER = 4,
	OTHER = 5
};

void	load_sprite(t_game *game, char *name, int sprite_number, int type);

#endif